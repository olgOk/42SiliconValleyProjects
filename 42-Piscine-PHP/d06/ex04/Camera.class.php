<?php
    require_once '../ex03/Matrix.class.php';
    require_once '../ex01/Vertex.class.php';
    class Camera {
        static public $verbose = FALSE;
        private $_position;
        private $_width;
		private $_height;
        private $_translate_matrix;
        private $_rotate_matrix;
        private $_projection_matrix;
        private $_world_coord;

        public function __construct($arr) {
            $this->_position = $arr["origin"];
            $this->_translate_matrix = new Matrix(array("preset" => Matrix::TRANSLATION, "vtc" => (new Vector(array("dest" => $this->_position)))->opposite()));
            $this->_rotate_matrix = $arr["orientation"];
            $this->_rotate_matrix = clone $this->_rotate_matrix;
            if (isset($arr["ratio"])) {
                $ratio = $arr["ratio"];
                $this->_width = 1920;
                $this->_height = 1920 / $ratio;
            } else {
                $this->_width = $arr["width"];
                $this->_height = $arr["height"];
                $ratio = $this->_width / $this->_height;
            }
            $fov =  $arr["fov"];
            $near =  $arr["near"];
            $far =  $arr["far"];
            $this->_world_coord = $this->_rotate_matrix->mult($this->_translate_matrix);
            $this->_projection_matrix = new Matrix(array("preset" => Matrix::PROJECTION, "fov" => $fov, "ratio" => $ratio, "far" => $far, "near" => $near));
            if (Camera::$verbose) {
                echo "Camera instance constracted\n";
            }
        }

        public function __destruct(){
            if (self::$verbose)
                echo "Camera instance destructed\n";
        }
        public function doc(){
            $doc = file_get_contents('Camera.doc.txt');
            echo "\n".$doc."\n";
        }
        public function __toString(){
            $string = "Camera( \n";
            $string.= "+ Origine: ".$this->_position."\n";
            $string.= "+ tT:\n";
            $string.= $this->_translate_matrix;
            $string.= "\n+ tR:\n";
            $string.= $this->_rotate_matrix;
            $string.= "\n+ tR->mult( tT ):\n";
            $string.= $this->_world_coord;
            $string.= "\n+ Proj:\n";
            $string.= $this->_projection_matrix;
            $string.= "\n)";
            return ($string);
        }

        public function watchVertex( Vertex $worldVertex ) {
            $worldVertex = $this->_projection_matrix->transformVertex($this->_world_coord->transformVertex($worldVertex));
            $worldVertex->setX(($worldVertex->getX() / ($this->_width / 2)) - 1);
            $worldVertex->setY(($worldVertex->getY() / ($this->_height / 2)) - 1);
            return ($worldVertex);
        }
    }
?>