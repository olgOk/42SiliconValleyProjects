<?php
    require_once('../ex01/Vertex.class.php');
    class Vector
    {
        private $_x				= 0;
        private $_y				= 0;
        private $_z				= 0;
        private $_w				= 0.0;
        static $verbose			= false;
        
        function __construct(array $arr)
        {
            if (isset($arr["dest"]) && $arr['dest'] instanceof Vertex)
            {
                if (isset($arr['orig']) && $arr['orig'] instanceof Vertex)
                {
                    $orig = new Vertex(array('x' => $arr['orig']->getX(),
                            'y' => $arr['orig']->getY(), 'z' => $arr['orig']->getZ()));
                } else {
                    $orig = new Vertex(array('x' => 0, 'y' => 0, 'z' => 0));
                }
                $this->_x = $arr['dest']->getX() - $orig->getX();
                $this->_y = $arr['dest']->getY() - $orig->getY();
                $this->_z = $arr['dest']->getZ() - $orig->getZ();
                $this->_w = 0;
            }
            if (Self::$verbose)
                printf("Vector( x:%0.2f, y:%0.2f, z:%0.2f, w:%0.2f ) constructed\n", $this->_x, $this->_y, $this->_z, $this->_w);
        }
        function __destruct()
        {
            if (Self::$verbose)
                printf("Vector( x:%0.2f, y:%0.2f, z:%0.2f, w:%0.2f ) destructed\n", $this->_x, $this->_y, $this->_z, $this->_w);
        }
        function __toString()
        {
            return (sprintf("Vector( x:%0.2f, y:%0.2f, z:%0.2f, w:%0.2f )",  $this->_x, $this->_y, $this->_z, $this->_w));
        }
        public static function doc()
        {
            if (file_exists('Vector.doc.txt'))
                return file_get_contents('Vector.doc.txt');
        }
        public function getX()
        {
            return $this->_x;
        }
        public function getY()
        {
            return $this->_y;
        }
        public function getZ()
        {
            return $this->_z;
        }
        public function getW()
        {
            return $this->_w;
        }
        public function magnitude()
        {
            return (float)sqrt(pow($this->_x, 2) + pow($this->_y, 2) + pow($this->_z, 2));
        }
        public function normalize()
        {
            $longth = $this->magnitude();
            if ($longth == 1)
                return clone $this;
            return (new Vector(array('dest' => new Vertex(array(
                    'x' => $this->_x / $longth,
                    'y' => $this->_y / $longth,
                    'z' => $this->_z / $longth)))));
        }
        public function add(Vector $rhs)
        {
            return (new Vector(array('dest' => new Vertex(array(
                    'x' => $this->_x + $rhs->_x,
                    'y' => $this->_y + $rhs->_y,
                    'z' => $this->_z + $rhs->_z)))));
        }
        public function sub(Vector $rhs)
        {
            return (new Vector(array('dest' => new Vertex(array(
                    'x' => $this->_x - $rhs->_x,
                    'y' => $this->_y - $rhs->_y,
                    'z' => $this->_z - $rhs->_z)))));
        }
        public function opposite()
        {
            return (new Vector(array('dest' => new Vertex(array(
                    'x' => $this->_x * -1,
                    'y' => $this->_y * -1,
                    'z' => $this->_z * -1)))));
        }
        public function scalarProduct($k)
        {
            return (new Vector(array('dest' => new Vertex(array(
                    'x' => $this->_x * $k,
                    'y' => $this->_y * $k,
                    'z' => $this->_z * $k)))));
        }
        public function dotProduct(Vector $rhs)
        {
            return (float)(($this->_x * $rhs->_x) + ($this->_y * $rhs->_y) + ($this->_z * $rhs->_z));
        }
        public function crossProduct(Vector $rhs)
        {
            return (new Vector(array('dest' => new Vertex(array(
                'x' => $this->_y * $rhs->getZ() - $this->_z * $rhs->getY(),
                'y' => $this->_z * $rhs->getX() - $this->_x * $rhs->getZ(),
                'z' => $this->_x * $rhs->getY() - $this->_y * $rhs->getX()
            )))));
        }
        public function cos(Vector $rhs)
        {
            $cross = ($this->_x * $rhs->_x) + ($this->_y * $rhs->_y) + ($this->_z * $rhs->_z);
            $pow_self = pow($this->_x, 2) + pow($this->_y, 2) + pow($this->_z, 2);
            $pow_rhs = pow($rhs->_x, 2) + pow($rhs->_y, 2) + pow($rhs->_z, 2);
            return ($cross / sqrt($pow_self * $pow_rhs));
        }
    }
?> 