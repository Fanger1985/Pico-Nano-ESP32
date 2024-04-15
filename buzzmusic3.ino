#define NOTE_B0 31
#define NOTE_C1 33
#define NOTE_CS1 35
#define NOTE_D1 37
#define NOTE_DS1 39
#define NOTE_E1 41
#define NOTE_F1 44
#define NOTE_FS1 46
#define NOTE_G1 49
#define NOTE_GS1 52
#define NOTE_A1 55
#define NOTE_AS1 58
#define NOTE_B1 62
#define NOTE_C2 65
#define NOTE_CS2 69
#define NOTE_D2 73
#define NOTE_DS2 78
#define NOTE_E2 82
#define NOTE_F2 87
#define NOTE_FS2 93
#define NOTE_G2 98
#define NOTE_GS2 104
#define NOTE_A2 110
#define NOTE_AS2 117
#define NOTE_B2 123
#define NOTE_C3 131
#define NOTE_CS3 139
#define NOTE_D3 147
#define NOTE_DS3 156
#define NOTE_E3 165
#define NOTE_F3 175
#define NOTE_FS3 185
#define NOTE_G3 196
#define NOTE_GS3 208
#define NOTE_A3 220
#define NOTE_AS3 233
#define NOTE_B3 247
#define NOTE_C4 262
#define NOTE_CS4 277
#define NOTE_D4 294
#define NOTE_DS4 311
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_FS4 370
#define NOTE_G4 392
#define NOTE_GS4 415
#define NOTE_A4 440
#define NOTE_AS4 466
#define NOTE_B4 494
#define NOTE_C5 523
#define NOTE_CS5 554
#define NOTE_D5 587
#define NOTE_DS5 622
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_FS5 740
#define NOTE_G5 784
#define NOTE_GS5 831
#define NOTE_A5 880
#define NOTE_AS5 932
#define NOTE_B5 988
#define NOTE_C6 1047
#define NOTE_CS6 1109
#define NOTE_D6 1175
#define NOTE_DS6 1245
#define NOTE_E6 1319
#define NOTE_F6 1397
#define NOTE_FS6 1480
#define NOTE_G6 1568
#define NOTE_GS6 1661
#define NOTE_A6 1760
#define NOTE_AS6 1865
#define NOTE_B6 1976
#define NOTE_C7 2093
#define NOTE_CS7 2217
#define NOTE_D7 2349
#define NOTE_DS7 2489
#define NOTE_E7 2637
#define NOTE_F7 2794
#define NOTE_FS7 2960
#define NOTE_G7 3136
#define NOTE_GS7 3322
#define NOTE_A7 3520
#define NOTE_AS7 3729
#define NOTE_B7 3951
#define NOTE_C8 4186
#define NOTE_CS8 4435
#define NOTE_D8 4699
#define NOTE_DS8 4978

// Define the pin the buzzer is attached to
int buzzerPin = 23;

// The setup remains the same
void setup() {
  // Set buzzer pin as output.
  pinMode(buzzerPin, OUTPUT);
}

// Expanded Mario melody
int marioMelody[] = {
  NOTE_E7, NOTE_E7, 0, NOTE_E7,
  0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0,  0,
  NOTE_G6, 0, 0, 0,
  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,
  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0
};

// Expanded Mario durations
int marioNoteDurations[] = {
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  9, 9, 9,
  12, 12, 12, 12,
  12, 9, 9, 9,
  12, 12, 12, 12, 12,
  12, 12, 12, 12
};

// Imperial March melody
int imperialMelody[] = {
  NOTE_A4, 0, NOTE_A4, 0, NOTE_A4, 0, NOTE_F4, NOTE_C5,
  NOTE_A4, 0, NOTE_F4, NOTE_C5, NOTE_A4, 0, 0, 0,
  NOTE_E5, 0, NOTE_E5, 0, NOTE_E5, 0, NOTE_F5, NOTE_C5,
  NOTE_A4, 0, NOTE_F4, NOTE_C5, NOTE_A4, 0, 0, 0
};

// Imperial March durations
int imperialNoteDurations[] = {
  500, 500, 500, 500, 500, 500, 350, 150,
  500, 500, 350, 150, 650, 500, 500, 500,
  500, 500, 500, 500, 500, 350, 150, 500,
  500, 350, 150, 650, 500, 500, 500, 500
};

// "You've Got a Friend in Me" melody
int friendMelody[] = {
  NOTE_G4, NOTE_E4, NOTE_C4, NOTE_D4, 
  NOTE_G4, NOTE_E4, NOTE_C4, NOTE_D4, 
  NOTE_G4, NOTE_E4, NOTE_C4, NOTE_D4, 
  NOTE_G4, NOTE_E4, NOTE_C4, NOTE_D4, 
  NOTE_G4, NOTE_B4, NOTE_D5, NOTE_G4, 
  NOTE_E4, NOTE_G4, NOTE_A4, NOTE_B4
};

// "You've Got a Friend in Me" note durations
int friendNoteDurations[] = {
  4, 8, 8, 4, 
  4, 8, 8, 4, 
  4, 8, 8, 4, 
  4, 8, 8, 4, 
  4, 4, 4, 4, 
  4, 4, 4, 2
};

// Jurassic Park Theme melody
int jurassicMelody[] = {
  NOTE_A4, NOTE_F4, NOTE_A4, // A - F - A
  NOTE_G4, 0, NOTE_G4, NOTE_E4, // G - rest - G - E
  NOTE_F4, NOTE_D4, NOTE_F4, // F - D - F
  NOTE_E4, 0, NOTE_E4, NOTE_C4, // E - rest - E - C
  NOTE_D4, NOTE_G4, NOTE_F4, // D - G - F
  NOTE_E4, // E
};

// Jurassic Park Theme note durations
int jurassicNoteDurations[] = {
  4, 8, 4, // dotted half note, eighth note, half note
  4, 8, 4, 4, // half note, eighth note, half note, quarter note
  4, 8, 4, // half note, eighth note, half note
  4, 8, 4, 4, // half note, eighth note, half note, quarter note
  4, 4, 4, // quarter note, quarter note, quarter note
  2, // half note
};

// The Pink Panther Theme melody
int pinkPantherMelody[] = {
  NOTE_DS4, NOTE_E4, NOTE_FS4, 0, NOTE_GS4, 0, NOTE_GS4, NOTE_G4, 
  NOTE_DS4, NOTE_E4, NOTE_FS4, 0, NOTE_GS4, NOTE_CS5, NOTE_C5, NOTE_B4, 
  NOTE_B4, NOTE_A4, NOTE_B4, 0, NOTE_E4, NOTE_GS4, NOTE_DS4, NOTE_E4, 
  NOTE_FS4, 0, NOTE_GS4, 0, NOTE_GS4, NOTE_G4, NOTE_DS4, NOTE_E4, 
  NOTE_FS4, 0, NOTE_GS4, NOTE_CS5, NOTE_C5, NOTE_B4, NOTE_B4, NOTE_A4, 
  NOTE_B4, 0, NOTE_E4, NOTE_GS4, NOTE_DS4, NOTE_E4, NOTE_FS4, 0
};

// The Pink Panther Theme note durations
int pinkPantherNoteDurations[] = {
  4, 4, 4, 4, 4, 4, 4, 2,
  4, 4, 4, 4, 4, 4, 4, 2,
  4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 2,
  4, 4, 4, 4, 4, 4, 4, 2,
  4, 4, 4, 4, 4, 4, 4, 4
};

// The Fresh Prince of Bel-Air Theme melody
int freshPrinceMelody[] = {
  NOTE_D4, NOTE_G4, 0, NOTE_C4, NOTE_D4, 0, NOTE_D4, NOTE_G4, 
  NOTE_D4, NOTE_C4, 0, NOTE_B3, NOTE_A3, NOTE_A3, 0, NOTE_G3,
  NOTE_A3, NOTE_B3, NOTE_C4, 0, NOTE_B3, NOTE_A3, NOTE_G3, 0, 
  NOTE_G3, NOTE_D4, NOTE_D4, 0, NOTE_D4, NOTE_G3, 0, NOTE_G3
};

// The Fresh Prince of Bel-Air Theme note durations
int freshPrinceNoteDurations[] = {
  8, 8, 4, 8, 8, 4, 8, 8,
  8, 8, 4, 8, 8, 4, 8, 8,
  8, 8, 8, 4, 8, 8, 8, 4,
  8, 8, 8, 4, 8, 8, 4, 8
};

// Aerith's Theme from Final Fantasy VII
int aerithMelody[] = {
  NOTE_C4, NOTE_E4, NOTE_G4, NOTE_C5, NOTE_B4, NOTE_G4,
  NOTE_E4, NOTE_G4, NOTE_A4, NOTE_F4, NOTE_G4, NOTE_E4,
  NOTE_D4, NOTE_F4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_D4,
  NOTE_E4, NOTE_G4, NOTE_C4, NOTE_C4, NOTE_D4, NOTE_G4,
  NOTE_E4, NOTE_C4, NOTE_A3, NOTE_A3, NOTE_B3, NOTE_E4,
  NOTE_D4, NOTE_B3, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_D4,
  NOTE_B3, NOTE_G3, NOTE_E3, NOTE_E3, NOTE_F3, NOTE_A3
};

// Note durations for Aerith's Theme
int aerithNoteDurations[] = {
  4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4
};

// Wutai Theme from Final Fantasy VII
int wutaiMelody[] = {
  NOTE_E4, NOTE_B3, NOTE_E4, NOTE_B3, NOTE_E4, NOTE_B3,
  NOTE_E4, NOTE_B3, NOTE_E4, NOTE_G4, NOTE_E4, NOTE_G4,
  NOTE_E4, NOTE_B3, NOTE_E4, NOTE_B3, NOTE_E4, NOTE_B3,
  NOTE_E4, NOTE_B3, NOTE_D4, NOTE_B3, NOTE_D4, NOTE_B3
};

// Note durations for Wutai Theme
int wutaiNoteDurations[] = {
  8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8
};

// Cosmo Canyon Theme from Final Fantasy VII
int cosmoCanyonMelody[] = {
  NOTE_D4, NOTE_F4, NOTE_A4, NOTE_D4, NOTE_F4, NOTE_A4,
  NOTE_D4, NOTE_F4, NOTE_A4, NOTE_D4, NOTE_C4, NOTE_E4,
  NOTE_G4, NOTE_C4, NOTE_E4, NOTE_G4, NOTE_C4, NOTE_E4,
  NOTE_G4, NOTE_C4, NOTE_B3, NOTE_D4, NOTE_G4, NOTE_B3
};

// Note durations for Cosmo Canyon Theme
int cosmoCanyonNoteDurations[] = {
  4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4
};

// Wind Scene from Chrono Trigger (600 A.D.)
int windSceneMelody[] = {
  NOTE_E4, NOTE_G4, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_A4,
  NOTE_A4, NOTE_D5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_G4, NOTE_E4, NOTE_C4,
  NOTE_C4, NOTE_E4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_G4, NOTE_A4,
  NOTE_B4, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_A4, NOTE_A4
};

// Note durations for Wind Scene (600 A.D.)
int windSceneNoteDurations[] = {
  8, 8, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 8, 8, 4,
  8, 8, 4, 4, 4, 8, 8, 4,
  4, 4, 4, 4, 4, 4, 4, 4
};
// Tetris Theme (Korobeiniki) melody corrected for rests
int tetrisMelody[] = {
  NOTE_E5, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_B4, NOTE_A4,
  NOTE_A4, NOTE_C5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_B4, NOTE_B4,
  NOTE_C5, NOTE_D5, NOTE_E5, NOTE_C5, NOTE_A4, NOTE_A4, 0,
  NOTE_D5, NOTE_F5, NOTE_A5, NOTE_G5, NOTE_F5, NOTE_E5, NOTE_C5,
  NOTE_E5, NOTE_D5, NOTE_C5, NOTE_B4, NOTE_B4, NOTE_C5, NOTE_D5,
  NOTE_E5, NOTE_C5, NOTE_A4, NOTE_A4
};

// Note durations for Tetris Theme (Korobeiniki)
int tetrisNoteDurations[] = {
  8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 16, // Rest length adjusted here if needed
  8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8
};

// Mario Pipe Sound effect
int marioPipeSound[] = {
  NOTE_G4, NOTE_F4, NOTE_E4, NOTE_C4, NOTE_A3
};

// Note durations for Mario Pipe Sound
int marioPipeNoteDurations[] = {
  10, 10, 10, 10, 10  // very quick succession to mimic the sliding effect
};

// Star Trek: The Next Generation Theme melody
int starTrekTNGMelody[] = {
  NOTE_B4, NOTE_FS5, NOTE_DS5, NOTE_B4, 
  NOTE_FS5, NOTE_DS5, NOTE_FS5, NOTE_B4,
  NOTE_FS5, NOTE_DS5, NOTE_B4, NOTE_FS5,
  NOTE_DS5, NOTE_FS5, NOTE_B4, NOTE_FS5
};

// Note durations for Star Trek: TNG Theme
int starTrekTNGNoteDurations[] = {
  4, 4, 4, 4,
  4, 4, 4, 4,
  4, 4, 4, 4,
  4, 4, 4, 4
};
// Super Mario Bros. Main Theme melody
int superMarioMelody[] = {
  NOTE_E5, NOTE_E5, 0, NOTE_E5,
  0, NOTE_C5, NOTE_E5, 0,
  NOTE_G5, 0, 0,  0,
  NOTE_G4, 0, 0, 0,

  NOTE_C5, 0, 0, NOTE_G4,
  0, 0, NOTE_E4, 0,
  0, NOTE_A4, 0, NOTE_B4,
  0, NOTE_AS4, NOTE_A4, 0,

  NOTE_G4, NOTE_E5, NOTE_G5,
  NOTE_A5, 0, NOTE_F5, NOTE_G5,
  0, NOTE_E5, 0, NOTE_C5,
  NOTE_D5, NOTE_B4, 0, 0
};

// Super Mario Bros. Main Theme note durations
int superMarioNoteDurations[] = {
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  9, 9, 9,
  12, 12, 12, 12,
  12, 9, 9, 9,
  12, 12, 12, 12
};

// Zelda's Lullaby from The Legend of Zelda series
int zeldasLullabyMelody[] = {
  NOTE_B4, NOTE_F4, NOTE_D4, NOTE_B4,
  NOTE_D5, NOTE_G4, NOTE_E4, NOTE_G4,
  NOTE_A4, NOTE_F4, NOTE_D4, NOTE_F4,
  NOTE_E4, NOTE_C5, NOTE_A4, NOTE_F4,

  NOTE_G4, NOTE_E4, NOTE_G4, NOTE_F4,
  NOTE_D4, NOTE_B4, NOTE_G4, NOTE_E4,
  NOTE_F4, NOTE_D4, NOTE_F4, NOTE_E4,
  NOTE_D4, NOTE_B4, NOTE_G4, NOTE_E4
};

// Note durations for Zelda's Lullaby
int zeldasLullabyNoteDurations[] = {
  4, 4, 4, 4,
  4, 4, 4, 4,
  4, 4, 4, 4,
  4, 4, 4, 4,

  4, 4, 4, 4,
  4, 4, 4, 4,
  4, 4, 4, 4,
  4, 4, 4, 4
};

// Pac-Man Opening Theme melody
int pacManMelody[] = {
  NOTE_B5, NOTE_B5, NOTE_FS5, NOTE_DS5, NOTE_B5,
  NOTE_FS5, NOTE_DS5, NOTE_B5, NOTE_B5, NOTE_FS5,
  NOTE_DS5, NOTE_FS5, NOTE_DS5, NOTE_FS5
};

// Note durations for Pac-Man Theme
int pacManNoteDurations[] = {
  8, 8, 8, 8, 8,
  8, 8, 8, 8, 8,
  8, 8, 8, 8
};

// "Words Drowned by Fireworks" from Final Fantasy VII melody
int wordsDrownedMelody[] = {
  NOTE_C5, NOTE_E5, NOTE_G5, NOTE_C6,
  NOTE_A5, NOTE_F5, NOTE_A5, NOTE_C5,
  NOTE_E5, NOTE_A5, NOTE_G5, NOTE_E5,
  NOTE_D5, NOTE_F5, NOTE_A5, NOTE_G5,

  NOTE_E5, NOTE_C5, NOTE_E5, NOTE_G5,
  NOTE_E5, NOTE_G5, NOTE_C6, NOTE_A5,
  NOTE_F5, NOTE_A5, NOTE_C5, NOTE_E5,
  NOTE_A5, NOTE_G5, NOTE_F5, NOTE_D5
};

// Note durations for "Words Drowned by Fireworks"
int wordsDrownedNoteDurations[] = {
  4, 4, 4, 4,
  4, 4, 4, 4,
  4, 4, 4, 4,
  4, 4, 4, 4,

  4, 4, 4, 4,
  4, 4, 4, 4,
  4, 4, 4, 4,
  4, 4, 4, 4
};
// "The Nightmare Begins" from Final Fantasy VII melody
int nightmareBeginsMelody[] = {
  NOTE_E4, NOTE_G4, NOTE_B4, NOTE_D5,
  NOTE_E5, NOTE_D5, NOTE_B4, NOTE_G4,
  NOTE_E4, NOTE_G4, NOTE_B4, NOTE_D5,
  NOTE_E5, NOTE_D5, NOTE_B4, NOTE_G4,

  NOTE_E4, NOTE_G4, NOTE_B4, NOTE_D5,
  NOTE_E5, NOTE_D5, NOTE_B4, NOTE_G4,
  NOTE_E4, NOTE_G4, NOTE_B4, NOTE_D5,
  NOTE_E5, NOTE_D5, NOTE_B4, NOTE_G4
};

// Note durations for "The Nightmare Begins"
int nightmareBeginsNoteDurations[] = {
  8, 8, 8, 8,
  4, 4, 8, 8,
  8, 8, 8, 8,
  4, 4, 8, 8,

  8, 8, 8, 8,
  4, 4, 8, 8,
  8, 8, 8, 8,
  4, 4, 8, 8
};

// Take Me Out to the Ball Game melody
int ballGameMelody[] = {
  NOTE_G4, NOTE_C5, NOTE_E5, NOTE_G5, 
  NOTE_E5, NOTE_C5, NOTE_G4, NOTE_E4,
  NOTE_G4, NOTE_A4, NOTE_B4, NOTE_A4,
  NOTE_G4, NOTE_E4, NOTE_C4, NOTE_D4,
  NOTE_E4, NOTE_G4, NOTE_E4, NOTE_C4,
  NOTE_G4, NOTE_E4, NOTE_C4, NOTE_D4,
  NOTE_E4, NOTE_C4, NOTE_G3
};

// Note durations for Take Me Out to the Ball Game
int ballGameNoteDurations[] = {
  4, 4, 4, 4, 
  4, 4, 4, 4,
  4, 4, 4, 4,
  4, 4, 4, 4,
  4, 4, 4, 4,
  4, 4, 4, 4,
  4, 4, 2
};
// We’ll wrap the playing into functions to keep it organized:
void playMelody(int buzzerPin, int melody[], int noteDurations[], int length) {
  for (int thisNote = 0; thisNote < length; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    if (melody[thisNote] == 0) {
      noTone(buzzerPin); // Stop playing any tone
    } else {
      tone(buzzerPin, melody[thisNote], noteDuration); // Play the note
    }
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(buzzerPin); // Ensure the tone is stopped before the next note
  }
}

void loop() {
  Serial.begin(9600); // Make sure to initialize serial communication
  
  Serial.println("Playing Take Me Out to the Ball Game...");
  playMelody(buzzerPin, ballGameMelody, ballGameNoteDurations, sizeof(ballGameMelody) / sizeof(int));
  delay(1500); // Short pause between songs

  Serial.println("Playing 'The Nightmare Begins' from FFVII...");
  playMelody(buzzerPin, nightmareBeginsMelody, nightmareBeginsNoteDurations, sizeof(nightmareBeginsMelody) / sizeof(int));
  delay(1500); // Short pause between songs

  Serial.println("Playing 'Words Drowned by Fireworks' from FFVII...");
  playMelody(buzzerPin, wordsDrownedMelody, wordsDrownedNoteDurations, sizeof(wordsDrownedMelody) / sizeof(int));
  delay(1500); // Short pause between songs

  Serial.println("Playing Pac-Man Opening Theme...");
  playMelody(buzzerPin, pacManMelody, pacManNoteDurations, sizeof(pacManMelody) / sizeof(int));
  delay(1500); // Short pause between songs

  Serial.println("Playing Zelda's Lullaby...");
  playMelody(buzzerPin, zeldasLullabyMelody, zeldasLullabyNoteDurations, sizeof(zeldasLullabyMelody) / sizeof(int));
  delay(1500); // Short pause between songs

  Serial.println("Playing Super Mario Bros. Main Theme...");
  playMelody(buzzerPin, superMarioMelody, superMarioNoteDurations, sizeof(superMarioMelody) / sizeof(int));
  delay(1500); // Short pause between songs

  Serial.println("Playing Star Trek: TNG Theme...");
  playMelody(buzzerPin, starTrekTNGMelody, starTrekTNGNoteDurations, sizeof(starTrekTNGMelody) / sizeof(int));
  delay(1500); // Short pause between songs

  Serial.println("Playing Mario Pipe Sound...");
  playMelody(buzzerPin, marioPipeSound, marioPipeNoteDurations, sizeof(marioPipeSound) / sizeof(int));
  delay(1500); // Short pause between sounds

  Serial.println("Playing Tetris Theme...");
  playMelody(buzzerPin, tetrisMelody, tetrisNoteDurations, sizeof(tetrisMelody) / sizeof(int));
  delay(1500); // Short pause between songs

  Serial.println("Playing Wind Scene from Chrono Trigger...");
  playMelody(buzzerPin, windSceneMelody, windSceneNoteDurations, sizeof(windSceneMelody) / sizeof(int));
  delay(1500); // Short pause between songs

  Serial.println("Playing Wutai Theme...");
  playMelody(buzzerPin, wutaiMelody, wutaiNoteDurations, sizeof(wutaiMelody) / sizeof(int));
  delay(1500); // Short pause between songs

  Serial.println("Playing Cosmo Canyon Theme...");
  playMelody(buzzerPin, cosmoCanyonMelody, cosmoCanyonNoteDurations, sizeof(cosmoCanyonMelody) / sizeof(int));
  delay(1500); // Short pause before the loop repeats

  Serial.println("Playing Aerith's Theme...");
  playMelody(buzzerPin, aerithMelody, aerithNoteDurations, sizeof(aerithMelody) / sizeof(int));
  delay(1500); // Delay before replaying the loop

  Serial.println("Playing The Fresh Prince of Bel-Air Theme...");
  playMelody(buzzerPin, freshPrinceMelody, freshPrinceNoteDurations, sizeof(freshPrinceMelody) / sizeof(freshPrinceMelody[0]));
  delay(1500);

  Serial.println("Playing The Pink Panther Theme...");
  playMelody(buzzerPin, pinkPantherMelody, pinkPantherNoteDurations, sizeof(pinkPantherMelody) / sizeof(pinkPantherMelody[0]));
  delay(1500);

  Serial.println("Playing You've Got a Friend in Me...");
  playMelody(buzzerPin, friendMelody, friendNoteDurations, sizeof(friendMelody) / sizeof(friendMelody[0]));
  delay(1500);

  Serial.println("Playing Super Mario Theme...");
  playMelody(buzzerPin, marioMelody, marioNoteDurations, sizeof(marioMelody) / sizeof(marioMelody[0]));
  delay(1500);

  Serial.println("Playing The Imperial March...");
  playMelody(buzzerPin, imperialMelody, imperialNoteDurations, sizeof(imperialMelody) / sizeof(imperialMelody[0]));
  delay(1500);

  Serial.println("Playing Jurassic Park Theme...");
  playMelody(buzzerPin, jurassicMelody, jurassicNoteDurations, sizeof(jurassicMelody) / sizeof(jurassicMelody[0]));
  delay(3000);

  Serial.println("End of loop, restarting...");
}

