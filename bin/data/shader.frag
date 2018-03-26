uniform vec2 u_resolution; // 画面の解像度(width,height)
uniform float u_time; // 起動してからの経過時間(秒)
void main() {
    //画面の解像度から、0.0～1.0に正規化する
    vec2 st = gl_FragCoord.xy / u_resolution;
    // 色を格納する変数
    vec3 color;
    // RGBそれぞれの時間で変化するグラデーションを生成
    color.r = abs(sin(u_time * 1.5 + st.x));
    color.g = abs(sin(u_time * 2.0 + st.y));
    color.b = abs(sin(u_time * 4.0 + st.y));
    // 合成して出力
    gl_FragColor = vec4(color.r, color.g, color.b, 0.4);
}
