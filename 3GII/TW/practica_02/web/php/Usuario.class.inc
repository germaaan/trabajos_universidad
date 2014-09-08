<?php 
	require_once "configuracion.inc";
	require_once "DataObject.class.inc";
	
	class Usuario extends DataObject{
		
		protected $datos = array(
			"usuario" => "",
			"pass" => "",
			"nombre" => "",
			"apellidos" => "",
			"correo" => "",
			"direccion" => "",
			"cod_postal" => "",
			"ciudad" => "",
			"telefono" => "",
			"edad" => "",
			"como_conoci" => "");
	
		public static function accesoLogueo($usuario,$pass){
			$conexion = parent::conectar();
			
			$sql = "SELECT * FROM ".TABLA_USUARIOS." WHERE usuario = :usuario AND pass = :pass";
			
			try{
				$st = $conexion->prepare($sql);
				$st->bindValue(":usuario",$usuario,PDO::PARAM_STR);
				$st->bindValue(":pass",$pass,PDO::PARAM_STR);
				$st->execute();

				$result = $st->fetch();
				
				parent::desconectar($conexion);
				
				if($result){
					session_start();
					$_SESSION['usuario']=$usuario;
				}
			}catch(PDOException $e){
				parent::desconectar($conexion);
				die("Consulta fallida: ".$e->getMessage());
			}
		}
		
		public static function getNombreUsuario($usuario){
			$conexion = parent::conectar();
			
			$sql = "SELECT * FROM ".TABLA_USUARIOS." WHERE usuario = :usuario";
			
			try{
				$st = $conexion->prepare($sql);
				$st->bindValue(":usuario",$usuario,PDO::PARAM_STR);
				$st->execute();

				$result = $st->fetch();
				
				parent::desconectar($conexion);
				
				if($result)
					return $result["nombre"]." ".$result["apellidos"];
				else
					return NULL;
			}catch(PDOException $e){
				parent::desconectar($conexion);
				die("Consulta fallida: ".$e->getMessage());
			}
		}
		
		public static function existeUsuario($usuario,$correo){
			$conexion = parent::conectar();
			
			$sql = "SELECT * FROM ".TABLA_USUARIOS." WHERE usuario = :usuario OR correo = :correo";
			
			try{
				$st = $conexion->prepare($sql);
				$st->bindValue(":usuario",$usuario,PDO::PARAM_STR);
				$st->bindValue(":correo",$correo,PDO::PARAM_STR);
				$st->execute();

				$result = $st->fetch();
				
				parent::desconectar($conexion);
				
				if($result)
					return true;
			}catch(PDOException $e){
				parent::desconectar($conexion);
				die("Consulta fallida: ".$e->getMessage());
			}
		}
			
		public static function insertarUsuario($usuario,$pass,$nombre,$apellidos,$correo,$direccion,$cod_postal,$ciudad,$telefono,$edad,$como_conoci){
			$conexion = parent::conectar();
		
			$sql = "INSERT INTO ".TABLA_USUARIOS." VALUES(:usuario,:pass,:nombre,:apellidos,:correo,:direccion,:cod_postal,:ciudad,:telefono,:edad,:como_conoci)";
				
			try {
				$st = $conexion->prepare($sql);
				$st->bindValue(":usuario",$usuario,PDO::PARAM_STR);
				$st->bindValue(":pass",$pass,PDO::PARAM_STR);
				$st->bindValue(":nombre",$nombre,PDO::PARAM_STR);
				$st->bindValue(":apellidos",$apellidos,PDO::PARAM_STR);
				$st->bindValue(":correo",$correo,PDO::PARAM_STR);
				$st->bindValue(":direccion",$direccion,PDO::PARAM_STR);
				$st->bindValue(":cod_postal",$cod_postal,PDO::PARAM_STR);
				$st->bindValue(":ciudad",$ciudad,PDO::PARAM_STR);
				$st->bindValue(":telefono",$telefono,PDO::PARAM_STR);
				$st->bindValue(":edad",$edad,PDO::PARAM_INT);
				$st->bindValue(":como_conoci",$como_conoci,PDO::PARAM_STR);
				$st->execute();
				
				parent::desconectar($conexion);
			}
			catch ( PDOException $e) {
				parent::desconectar($conexion);
				exit( 'Conexión fallida: '. $e->getMessage() );
			}
		}

	}
?>