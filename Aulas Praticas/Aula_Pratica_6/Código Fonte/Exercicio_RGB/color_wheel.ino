const int redPin = 3; //Pino do RED
const int greenPin = 5; //Pino do GREEN
const int bluePin = 6; //Pino do BLUE
const bool invert = true;
int color = 0; // valor HUE
int R, G, B; // variáveis RGB

void setup() {
  // pins driven by analogWrite do not need to be declared as outputs
}
void loop() {
  // Valor do brilho (0 - 255)
  int brightness = 255;

  hueToRGB(color, brightness);

  // Fornecer valores às variáveis
  analogWrite(redPin, R);
  analogWrite(greenPin, G);
  analogWrite(bluePin, B);

  color++;

  if (color > 255)
    color = 0;

  delay(25);
}

//Função de conversão da cor para os componentes RGB
void hueToRGB(int hue, int brightness) {
  //Hue à escala
  unsigned int scaledHue = (hue * 6);

  //Segmento de 0 a 5 (ciclo de cores)
  unsigned int segment = scaledHue / 256;

  //Posição no segmento
  unsigned int segmentOffset = scaledHue - (segment * 256);
  
  unsigned int complement = 0;
  unsigned int prev = (brightness * (255 - segmentOffset)) / 256;
  unsigned int next = (brightness * segmentOffset) / 256;
  
  if (invert) {
    brightness = 255 - brightness;
    complement = 255;
    prev = 255 - prev;
    next = 255 - next;
  }

  switch (segment) {
    case 0:  // red
      R = brightness;
      G = next;
      B = complement;
      break;
    case 1:  // yellow
      R = prev;
      G = brightness;
      B = complement;
      break;
    case 2:  // green
      R = complement;
      G = brightness;
      B = next;
      break;
    case 3:  // cyan
      R = complement;
      G = prev;
      B = brightness;
      break;
    case 4:  // blue
      R = next;
      G = complement;
      B = brightness;
      break;
    case 5:  // magenta
    default:
      R = brightness;
      G = complement;
      B = prev;
      break;
  }
}