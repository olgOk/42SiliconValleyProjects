<?php
    require_once('../ex00/Color.class.php');

    class Vertex{
        private $_x;
        private $_y;
        private $_z;
        private $_w;
        private $_color;
        static public $verbose = FALSE;

        public function __construct($arr){
            $this->_x = $arr["x"];
            $this->_y = $arr["y"];
            $this->_z = $arr["z"];
            if (isset($arr["w"]))
                $this->_w = $arr["w"];
            else
                $this->_w = 1.0;
            $this->_color = new Color(array('rgb' => 0xffffff));
            if (isset($arr["color"]) && $arr["color"] instanceof Color)
                $this->_color = $arr["color"];
            if (self::$verbose)
                echo $this."constructed.\n";
        }
        public function __destruct(){
            if (self::$verbose)
                echo $this."destructed.\n";
        }
        static function doc(){
            $doc = file_get_contents('Vertex.doc.txt');
            echo "\n".$doc."\n";
        }
        public function __toString(){
            $str = "Vertex( x: ".sprintf("%.2f", $this->_x).", y: ".sprintf("%.2f", $this->_y).", z:".sprintf("%.2f", $this->_z).", w:".sprintf("%.2f", $this->_w)."";
			if (self::$verbose) {
				$str = $str.", ".$this->_color;
			}
			return ($str." )");
        }
        public function setX($x){
            $this->_x = $x;
        }
        public function setY($y){
            $this->_y = $y;
        }
        public function setZ($z){
            $this->_z = $z;
        }
        public function setW($w){
            $this->_w = $w;
        }
        public function setColor($color){
            $this->_color = $color;
        }
        public function getX(){
            return ($this->_x);
        }
        public function getY(){
            return ($this->_y);
        }
        public function getZ(){
            return ($this->_z);
        }
        public function getW(){
            return ($this->_w);
        }
        public function getColor(){
            return ($this->_color);
        }
    }
?>