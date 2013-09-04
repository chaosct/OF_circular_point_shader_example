uniform vec2 windowSize;
varying vec2 screenPos;
varying float radius;
attribute float part_size;

void main() {
  gl_Position = ftransform();
  gl_FrontColor = gl_Color;
  screenPos = vec2(gl_Vertex.x, windowSize.y-gl_Vertex.y); 	//change this if working inside an FBO
  // screenPos = vec2(gl_Vertex.x, gl_Vertex.y); 			//
  radius = part_size;
}

