<?php
    class NightsWatch implements IFighter {
        private $_nw;
        
		public function __construct () {
			$this->_nw = array();
		}
		public function recruit($obj) {
			array_push($this->_nw, $obj);
		}
		public function fight() {
			foreach ($this->_nw as $val) {
				if ($val instanceof IFighter) {
					$val->fight();
				}
			}
		}
	}
?>