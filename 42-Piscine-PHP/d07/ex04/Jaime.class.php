<?php
    class Jaime{
        public function sleepWith($str){
            if ($str instanceof Cersei) {
                print("With pleasure, but only in a tower in Winterfell, then." . PHP_EOL);
            }
            else if ($str instanceof Tyrion) {
                print("Not even if I'm drunk !" . PHP_EOL);
            }
            else if ($str instanceof Sansa) {
                print("Let's do this." . PHP_EOL);
            }
        }
    }
?>