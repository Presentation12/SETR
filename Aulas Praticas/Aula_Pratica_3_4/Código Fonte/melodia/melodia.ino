//First Octave

#define Red1 131      
#define DOrange1 277
#define Orange1 294
#define LOrange1 311
#define Yellow1 330
#define LGreen1 349
#define Green1 370
#define DGreen1 392
#define LBlue1 415
#define Blue1 440
#define Purple1 466
#define Pink1 494

//Second Octave

#define Red2 523
#define DOrange2 554
#define Orange2 587
#define LOrange2 622
#define Yellow2 659
#define LGreen2 698
#define Green2 740
#define DGreen2 784
#define LBlue2 831
#define Blue2 880
#define Purple2 932
#define Pink2 988

//Third Octave

#define Red3 1047
#define DOrange3 1109
#define Orange3 1175
#define LOrange3 1245
#define Yellow3 1319
#define LGreen3 1397
#define Green3 1480
#define DGreen3 1568
#define LBlue3 1661
#define Blue3 1760
#define Purple3 1865
#define Pink3 1976

int S[] = {
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, Pink2, 0, Pink2, 0, Pink2, Blue2, 0, Pink2, 0, Orange3, 0, Pink2, 0, Green2, Blue2, 0, Pink2, 0, Pink2, 0, Pink2, Blue2, 0, Pink2, 0, LGreen3, 0, Yellow3, 0, Orange3, Blue2, 0, Pink2, 0, Pink2, 0, Pink2, Blue2, 0, Pink2, 0, Orange3, 0, Pink2, 0, Green2, Blue2, 0, Pink2, 0, Pink2, 0, Pink2, 0, Blue2, Pink2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  Orange3, DOrange3, Pink2, 0, Blue2, 0, 0, Pink2, 0, 0, Pink2, 0, 0, 0, Green2, 0, Blue2, 0, Pink2, 0, DOrange3, 0, 0, Blue2, 0, 0, Pink2, 0, 0, 0, 0, 0, Orange3, DOrange3, Pink2, 0, Blue2, 0, 0, Pink2, 0, 0, Pink2, 0, 0, Green2, 0, 0, DOrange3, 0, Orange3, 0, DOrange3, 0, 0, Blue2, 0, DOrange2, Yellow2, Green2, DOrange2, Green2, LBlue2, Pink2, Orange3, DOrange3, Pink2, 0, Blue2, 0, 0, Pink2, 0, 0, Pink2, 0, 0, 0, Green2, 0, Blue2, 0, Pink2, 0, DOrange3, 0, 0, Blue2, 0, 0, Pink2, 0, 0, 0, 0, 0, Orange3, DOrange3, Pink2, 0, Blue2, Orange3, 0, Green3, Yellow3, Orange3, Pink2, 0, Blue3, LBlue3, 0, Green3, Orange3, DOrange3, 0, Pink2, Blue2, Pink2, 0, Blue2, Pink2, 0, Blue2, Pink2, 0, Blue2, Pink2, 0, Blue2, Pink2, Orange3, 0,
  Green2, 0, 0, 0, 0, 0, Orange2, 0, 0, 0, 0, 0, 0, Orange2, Yellow2, LGreen2, 0, 0, Yellow2, 0, 0, Orange2, 0, DOrange2, 0, 0, Orange2, 0, 0, Yellow2, 0, Green2, 0, 0, 0, 0, 0, Pink2, 0, 0, 0, 0, 0, Pink1, 0, DOrange2, 0, Orange2, 0, 0, Yellow2, 0, 0, Orange2, 0, DOrange2, 0, 0, Blue2, 0, 0, DGreen2, 0, Green2, 0, 0, 0, 0, 0, Orange2, 0, 0, 0, 0, 0, 0, Orange2, Yellow2, LGreen2, 0, 0, Yellow2, 0, 0, Orange2, 0, DOrange2, 0, 0, Orange2, 0, 0, Yellow2, 0, Green2, 0, 0, 0, 0, 0, Pink2, 0, 0, 0, 0, 0, Pink2, 0, DOrange3, 0, Orange3, 0, 0, DGreen3, 0, 0, Green3, 0, LGreen3, 0, 0, Orange3, 0, 0, Purple2, 0, Pink2
  
};
int L = sizeof(S);
int nds = 10;

void setup() {
  Serial.begin(115200);
  pinMode(3, INPUT_PULLUP);
  L = L / 2;
  Serial.println(L);
}

void loop() {
  if(!digitalRead(3)) {
    Tone();
  }
}

void Tone() {
  for (int n = 0; n < L; n++) {
    int nd = 1000 / nds;
    tone(6, S[n], nd);
    int d = nd * 1.2;
    delay(d);
    noTone(6);
  }
}