#include <windows.h>

void notification_sound()
{
    float g3s = 207.652;
    float c4 = 261.626;
    float c4s = 277.183;
    float d4 = 293.665;
    float d4s = 311.127;
    float e4 = 329.628;
    float f4 = 349.228;
    float f4s = 369.994;
    float g4 = 391.995;
    float g4s = 415.305;
    float a4 = 440.000;
    float a4s = 466.164;
    float b4 = 493.883;

    int whole_note=1000;
    int half_note=500;
    int quarter_note=250;
    int eighteenth_note=1000/8;
    int sixteenth_note=1000/16;

        Beep(c4s,half_note);
        Beep(d4s,half_note);
        Beep(g3s,half_note);
        Beep(d4s,half_note);
        Beep(f4,half_note);
        Beep(g4s,quarter_note);
        Beep(f4s,quarter_note);
        Beep(f4,quarter_note);
        Beep(d4s,quarter_note);
        Beep(c4s,half_note);
        Beep(d4s,half_note);
        Beep(g3s,half_note);

        Sleep(2500);

        Beep(c4s,half_note);
        Beep(d4s,half_note);
        Beep(g3s,half_note);
        Beep(d4s,half_note);
        Beep(f4,half_note);
        Beep(g4s,quarter_note);
        Beep(f4s,quarter_note);
        Beep(f4,quarter_note);
        Beep(d4s,quarter_note);
        Beep(c4s,half_note);
        Beep(d4s,half_note);
        Beep(g3s,half_note);

        Sleep(2500);

        Beep(c4s,half_note);
        Beep(d4s,half_note);
        Beep(g3s,half_note);
        Beep(d4s,half_note);
        Beep(f4,half_note);
        Beep(g4s,quarter_note);
        Beep(f4s,quarter_note);
        Beep(f4,quarter_note);
        Beep(d4s,quarter_note);
        Beep(c4s,half_note);
        Beep(d4s,half_note);
        Beep(g3s,half_note);
}