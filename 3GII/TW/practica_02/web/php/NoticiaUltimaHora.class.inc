<?php 
	require_once "configuracion.inc";
	require_once "DataObject.class.inc";
	
	class NoticiaUltimaHora extends DataObject{
		
		protected $datos = array(
			"id_noticia" => "",
			"texto" => "");
		
		public static function getNoticiasUltimaHora(){
			$conexion = parent::conectar();
			
			$sql = "SELECT * FROM ".TABLA_NOTICIAS;
			
			try{
				$st = $conexion->prepare($sql);
				$st->execute();
				$noticias = array();

				foreach($st->fetchAll() as $fila){
					$noticias[] = new NoticiaUltimaHora($fila);
				}
				
				parent::desconectar($conexion);
				
				return $noticias;
			}catch(PDOException $e){
				parent::desconectar($conexion);
				die("Consulta fallida: ".$e->getMessage());
			}
		}
		
		public static function mostrarNoticias($datos){
			echo "<ul style='list-style-type:circle'>";
			
			foreach($datos as $noticia){
				echo "<li>".$noticia->getTexto()."</li>";
			}
			
			echo "</ul>";
		}
		
		public static function mostrarNoticiasAvanzado($datos){
			echo "<ul style='list-style-type:disc'>";
			
			foreach($datos as $noticia){
				echo "<li><strong>Id:</strong> ".$noticia->getIdNoticia();
				echo ". <strong>Texto:</strong> ".$noticia->getTexto()."</li><br>";
			}
			
			echo "</ul>";
		}
		
		public static function insertarNoticia($texto){
			$conexion = parent::conectar();
			$sql = "INSERT INTO ".TABLA_NOTICIAS." VALUES(NULL, :texto)";
				
			try {
				$st = $conexion->prepare($sql);
				$st->bindValue(":texto",$texto,PDO::PARAM_STR);
				$st->execute();
				
				parent::desconectar($conexion);
			}
			catch ( PDOException $e) {
				parent::desconectar($conexion);
				exit( 'Conexión fallida: '. $e->getMessage() );
			}
		}

		public static function actualizarNoticia($id, $texto){
			$conexion = parent::conectar();
			$sql = "UPDATE ".TABLA_NOTICIAS." SET texto = :texto WHERE id_noticia = :id";
				
			try {
				$st = $conexion->prepare($sql);
				$st->bindValue(":texto",$texto,PDO::PARAM_STR);
				$st->bindValue(":id",$id,PDO::PARAM_INT);
				$st->execute();
				
				parent::desconectar($conexion);
			}
			catch ( PDOException $e) {
				parent::desconectar($conexion);
				exit( 'Conexión fallida: '. $e->getMessage() );
			}
		}
		
		public static function eliminarNoticia($id){
			$conexion = parent::conectar();
			$sql = "DELETE FROM ".TABLA_NOTICIAS." WHERE id_noticia = :id";
				
			try {
				$st = $conexion->prepare($sql);
				$st->bindValue(":id",$id,PDO::PARAM_INT);
				$st->execute();
				
				parent::desconectar($conexion);
			}
			catch ( PDOException $e) {
				parent::desconectar($conexion);
				exit( 'Conexión fallida: '. $e->getMessage() );
			}
		}
		
		public function getIdNoticia(){
			return $this->datos["id_noticia"];
		}
		
		public function getTexto(){
			return $this->datos["texto"];
		}
		
	}
?>