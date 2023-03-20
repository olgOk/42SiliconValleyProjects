<?php
    class Tyrion{
        public function sleepWith($str){
            if ($str instanceof Jaime) {
				print("Not even if I'm drunk !" . PHP_EOL);
			} else if ($str instanceof Cersei) {
                print("Not even if I'm drunk !" . PHP_EOL);
            } else if ($str instanceof Sansa) {
				print("Let's do this." . PHP_EOL);
			}
        }
    }
?>