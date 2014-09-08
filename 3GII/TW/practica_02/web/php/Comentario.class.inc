<?php 
	require_once "configuracion.inc";
	require_once "DataObject.class.inc";
	
	class Comentario extends DataObject{
		
		protected $datos = array(
			"id_comentario" => "",
			"nombre_noticia" => "",
			"usuario" => "",
			"fecha_hora" => "",
			"texto" => "");
		
		public static function insertarComentario($nombre_noticia, $usuario, $texto){
			$conexion = parent::conectar();
			$sql = "INSERT INTO ".TABLA_COMENTARIOS." VALUES(NULL, :nombre_noticia, :usuario, CURRENT_TIMESTAMP, :texto)";
				
			try {
				$st = $conexion->prepare($sql);
				$st->bindValue(":nombre_noticia",$nombre_noticia,PDO::PARAM_STR);
				$st->bindValue(":usuario",$usuario,PDO::PARAM_STR);
				$st->bindValue(":texto",$texto,PDO::PARAM_STR);
				$st->execute();
				
				parent::desconectar($conexion);
			}
			catch ( PDOException $e) {
				parent::desconectar($conexion);
				exit( 'Conexión fallida: '. $e->getMessage() );
			}
		}
		
		public static function getComentarios($nombre_noticia){
			$conexion = parent::conectar();
			
			$sql = "SELECT * FROM ".TABLA_COMENTARIOS." WHERE nombre_noticia = :nombre_noticia";
			
			try{
				$st = $conexion->prepare($sql);
				$st->bindValue(":nombre_noticia",$nombre_noticia,PDO::PARAM_STR);
				$st->execute();
				$noticias = array();

				foreach($st->fetchAll() as $fila){
					$noticias[] = new Comentario($fila);
				}
				
				parent::desconectar($conexion);
				
				return $noticias;
			}catch(PDOException $e){
				parent::desconectar($conexion);
				die("Consulta fallida: ".$e->getMessage());
			}
		}
		
		public static function mostrarComentarios($datos){
			echo "<ul style='list-style-type:circle'>";
			
			foreach($datos as $comentario){
				echo "<li> Usuario: ".$comentario->getUsuario().". Fecha: ".$comentario->getFecha()."<br>Comentario: ".$comentario->getTexto()."</li>";
			}
			
			echo "</ul>";
		}
		
		public function getUsuario(){
			return $this->datos["usuario"];
		}
		
		public function getFecha(){
			return $this->datos["fecha_hora"];
		}
		
		public function getTexto(){
			return $this->datos["texto"];
		}
		
	}
?>