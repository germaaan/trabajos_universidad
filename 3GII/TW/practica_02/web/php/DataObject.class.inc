<?php

abstract class DataObject{
	protected $datos = array();
 
	public function __construct( $datos ){
		foreach ( $datos as $clave => $valor ) {
			if ( array_key_exists( $clave, $this->datos ) )
				$this->datos[$clave] = $valor;
		}
	}
 
	public function getValor( $campo ){
		if ( array_key_exists( $campo, $this->datos ) )
			return $this->datos[$campo];
		else
			exit( "Campo no encontrado." );
	}
 
	protected function conectar(){
		try {
			$codif = array(PDO::MYSQL_ATTR_INIT_COMMAND => 'SET NAMES utf8',); 
			$conexion = new PDO( DB_DSN, DB_USUARIO, DB_PASS, $codif);
			$conexion->setAttribute( PDO::ATTR_PERSISTENT, TRUE );
			$conexion->setAttribute( PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION );
		}
		catch ( PDOException $e) {
			exit( 'Conexión fallida: '. $e->getMessage() );
		}
 
		return $conexion;
	}
 
	protected function desconectar( $conexion ){
		$conexion = NULL;
	}
}

?> 