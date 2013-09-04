varying vec2 screenPos;
varying float radius;

void main() {
  if( distance(gl_FragCoord.xy, screenPos) > radius ) discard;
  gl_FragColor = gl_Color;
  //gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);
}