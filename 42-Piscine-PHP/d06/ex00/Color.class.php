
<?php
    class Color{
        public $red = 0;
        public $green = 0;
        public $blue = 0;
        public static $verbose = FALSE;

        public function __construct($color){
            if (isset($color["red"]) && isset($color["green"]) && isset($color["blue"])){
                $this->red = $color["red"];
                $this->blue = $color["blue"];
                $this->green = $color["green"];
            } else if (isset($color["rgb"])){
                $this->red = $color["rgb"] >> 16;
                $this->green = $color["rgb"] >> 8;
                $this->blue = $color["rgb"] & 0xFF;
            }
            if (self::$verbose)
                echo $this."constructed.\n";
        }

        public function __destruct(){
            if (self::$verbose)
                echo $this."destructed.\n";
        }
        public function __toString(){
            return ("Color( red: ".sprintf("%3s", $this->red).", green: ".sprintf("%3s", $this->green).", blue: ".sprintf("%3s", $this->blue)." ) ");
        }
        public static function doc(){
            $doc = file_get_contents('Color.doc.txt');
            return "\n".$doc."\n";
        }
        public function add($color){
            $red = $this->red + $color->red;
            $green = $this->green + $color->green;
            $blue = $this->blue + $color->blue;
            return new Color (array('red' => $red, 'green' => $green, 'blue' => $blue));
        }
        public function sub($color){
            $red = $this->red - $color->red;
            $green = $this->green - $color->green;
            $blue = $this->blue - $color->blue;
            return new Color (array('red' => $red, 'green' => $green, 'blue' => $blue));
        }
        public function mult($f){
            $red = $this->red * $f;
            $green = $this->green * $f;
            $blue =  $this->blue * $f;
            return new Color (array('red' => $red, 'green' => $green, 'blue' => $blue));
        }
    }
?>