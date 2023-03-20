<?php
require_once '../ex02/Vector.class.php';

    class Matrix{
        public const IDENTITY = "IDENTITY";
        public const SCALE = "SCALE";
        public const RX = "X ROTATION";
        public const RY = "Y ROTATION";
        public const RZ = "Z ROTATION";
        public const TRANSLATION = "TRANSLATION";
        public const PROJECTION = "PROJECTION";

        private $_matrix;
        static public $verbose = FALSE;

        private function _initMatrix() {
            $x = array("vtcX" => 0, "vtcY" => 0, "vtcZ" => 0, "vtx0" => 0);
            $y = array("vtcX" => 0, "vtcY" => 0, "vtcZ" => 0, "vtx0" => 0);
            $z = array("vtcX" => 0, "vtcY" => 0, "vtcZ" => 0, "vtx0" => 0);
            $w = array("vtcX" => 0, "vtcY" => 0, "vtcZ" => 0, "vtx0" => 0);
            $this->_matrix = array("x" => $x, "y" => $y, "z" => $z, "w" => $w);
        }
        public function __construct($arr = NULL) {
                if (isset($arr)) {
                    $this->_initMatrix();
                    if (isset($arr["preset"])) {
                        $this->initProp($arr);
                    }
                if (self::$verbose) {
                    if ($arr["preset"] == self::IDENTITY) {
                        echo "Matrix IDENTITY instance constructed\n";
                    } else {
                        echo "Matrix".$arr["preset"]." preset instance constracted\n";
                    }
                }
            }
        }
        public function __destruct(){
            if (self::$verbose)
			    print("Matrix instance destructed\n");
        }
        public function doc(){
            $doc = file_get_contents('Matrix.doc.txt');
            echo "\n".$doc."\n";
        }
        public function __toString(){
            $str = sprintf("M | vtcX | vtcY | vtcZ | vtxO\n-----------------------------\nx | %0.2f | %0.2f | %0.2f | %0.2f\ny | %0.2f | %0.2f | %0.2f | %0.2f\nz | %0.2f | %0.2f | %0.2f | %0.2f\nw | %0.2f | %0.2f | %0.2f | %0.2f", $this->_matrix["x"]["vtcX"],
      $this->_matrix["x"]["vtcY"], $this->_matrix["x"]["vtcZ"],
      $this->_matrix["x"]["vtx0"], $this->_matrix["y"]["vtcX"],
      $this->_matrix["y"]["vtcY"], $this->_matrix["y"]["vtcZ"],
      $this->_matrix["y"]["vtx0"], $this->_matrix["z"]["vtcX"],
      $this->_matrix["z"]["vtcY"], $this->_matrix["z"]["vtcZ"],
      $this->_matrix["z"]["vtx0"], $this->_matrix["w"]["vtcX"],
      $this->_matrix["w"]["vtcY"], $this->_matrix["w"]["vtcZ"],
      $this->_matrix["w"]["vtx0"]);
    return $str;
        }

        public function initProp($arr){
            switch ($arr["preset"]) {
                case self::IDENTITY:
                    $this->_identity(1);
                    break;
                case self::SCALE:
                    $this->_scale($arr["scale"]);
                    break;
                case self::RX:
                    $this->_xrotation($arr["angle"]);
                    break;
                case self::RY:
                    $this->_yrotation($arr["angle"]);
                    break;
                case self::RZ:
                    $this->_zrotation($arr["angle"]);
                    break;
                case self::TRANSLATION:
                    if (isset($arr["vtc"]) && $arr["vtc"] instanceof Vector) {
                        $this->_translation($arr["vtc"]);
                    }
                    break;
                case self::PROJECTION:
                    if (isset($arr["fov"]) && isset($arr["ratio"])) {
                        $this->_projection($arr["fov"], $arr["ratio"], $arr["near"], $arr["far"]);
                    }
                    break;
            }
        }
        private function _identity($value) {
            $this->_matrix["x"]["vtcX"] = $value;
            $this->_matrix["y"]["vtcY"] = $value;
            $this->_matrix["z"]["vtcZ"] = $value;
            $this->_matrix["w"]["vtx0"] = 1;
        }
        private function _scale($scale) {
            $this->_matrix["x"]["vtcX"] = $scale;
            $this->_matrix["y"]["vtcY"] = $scale;
            $this->_matrix["z"]["vtcZ"] = $scale;
            $this->_matrix["w"]["vtx0"] = 1;
        }
        private function _xrotation($angle){
            $this->_identity(1);
            $this->_matrix["y"]["vtcY"] = cos($angle);
            $this->_matrix["y"]["vtcZ"] = -sin($angle);
            $this->_matrix["z"]["vtcY"] = sin($angle);
            $this->_matrix["z"]["vtcZ"] = cos($angle);
        }
        private function _yrotation($angle){
            $this->_identity(1);
            $this->_matrix["x"]["vtcX"] = cos($angle);
            $this->_matrix["x"]["vtcZ"] = sin($angle);
            $this->_matrix["z"]["vtcX"] = -sin($angle);
            $this->_matrix["z"]["vtcZ"] = cos($angle);
        }
        private function _zrotation($angle){
            $this->_identity(1);
            $this->_matrix["x"]["vtcX"] = cos($angle);
            $this->_matrix["x"]["vtcY"] = -sin($angle);
            $this->_matrix["y"]["vtcX"] = sin($angle);
            $this->_matrix["y"]["vtcY"] = -cos($angle);
        }
        private function _translation(Vector $vtc) {
            $this->_identity(1);
            $this->_matrix["x"]["vtx0"] = $vtc->getX();
            $this->_matrix["y"]["vtx0"] = $vtc->getY();
            $this->_matrix["z"]["vtx0"] = $vtc->getZ();

        }
        private function _projection($fov, $ratio, $near, $far) {
            $this->_identity(1);
            $this->_matrix["y"]["vtcY"] = 1 / tan(0.5 * deg2rad($fov));
            $this->_matrix["x"]["vtcX"] = $this->_matrix["y"]["vtcY"] / $ratio;
            $this->_matrix["z"]["vtcZ"] = ($near + $far) / ($near - $far);
            $this->_matrix["z"]["vtxO"] = (2 * $near * $far) / ($near - $far);
            $this->_matrix["w"]["vtcZ"] = -1;
            $this->_matrix["w"]["vtxO"] = 0;
        }
        private function _mult($row, $col, Matrix $rhs)
        {
            $res = $this->_matrix[$row]["vtcX"] * $rhs->_matrix["x"][$col];
            $res += $this->_matrix[$row]["vtcY"] * $rhs->_matrix["y"][$col];
            $res += $this->_matrix[$row]["vtcZ"] * $rhs->_matrix["z"][$col];
            $res += $this->_matrix[$row]["vtx0"] * $rhs->_matrix["w"][$col];
            return ($res);
        }
        public function mult(Matrix $rhs) {
            $x = array("vtcX" => $this->_mult("x", "vtcX", $rhs), "vtcY" => $this->_mult("x", "vtcY", $rhs), "vtcZ" => $this->_mult("x", "vtcZ", $rhs), "vtx0" => $this->_mult("x", "vtx0", $rhs));
            $y = array("vtcX" => $this->_mult("y", "vtcX", $rhs), "vtcY" => $this->_mult("y", "vtcY", $rhs), "vtcZ" => $this->_mult("y", "vtcZ", $rhs), "vtx0" => $this->_mult("y", "vtx0", $rhs));
            $z = array("vtcX" => $this->_mult("z", "vtcX", $rhs), "vtcY" => $this->_mult("z", "vtcY", $rhs), "vtcZ" => $this->_mult("z", "vtcZ", $rhs), "vtx0" => $this->_mult("z", "vtx0", $rhs));
            $w = array("vtcX" => $this->_mult("w", "vtcX", $rhs), "vtcY" => $this->_mult("w", "vtcY", $rhs), "vtcZ" => $this->_mult("w", "vtcZ", $rhs), "vtx0" => $this->_mult("w", "vtx0", $rhs));
            $resMatrix = array("x" => $x, "y" => $y, "z" => $z, "w" => $w);
            $res = new Matrix();
            $res->_matrix = $resMatrix;
            return $res;
        }
        public function transformVertex(Vertex $vtx){
            $x = $vtx->getX() * $this->_matrix["x"]["vtcX"] + $vtx->getY() * $this->_matrix["x"]["vtcY"] + $vtx->getZ() * $this->_matrix["x"]["vtcZ"] + $vtx->getW() * $this->_matrix["x"]["vtx0"];
            $y = $vtx->getX() * $this->_matrix["y"]["vtcX"] + $vtx->getY() * $this->_matrix["y"]["vtcY"] + $vtx->getZ() * $this->_matrix["y"]["vtcZ"] + $vtx->getW() * $this->_matrix["y"]["vtx0"];
            $z = $vtx->getX() * $this->_matrix["x"]["vtcX"] + $vtx->getY() * $this->_matrix["x"]["vtcY"] + $vtx->getZ() * $this->_matrix["x"]["vtcZ"] + $vtx->getW() * $this->_matrix["x"]["vtx0"];
            $w = $vtx->getX() * $this->_matrix["z"]["vtcX"] + $vtx->getY() * $this->_matrix["z"]["vtcY"] + $vtx->getZ() * $this->_matrix["z"]["vtcZ"] + $vtx->getW() * $this->_matrix["z"]["vtx0"];
            $color = $vtx->getColor();
            $newVertex = new Vertex(array("x" => $x, "y" => $y, "z" => $z, "w" => $w));
            return $newVertex;
        }
    }
?>