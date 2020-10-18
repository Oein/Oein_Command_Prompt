#include "./piano_header/functions.hpp"
#include "./piano_header/midiSoundPlay.hpp"
#include "./piano_header/functions.hpp"
#include "./cls.hpp"

void piano()
{
    cls();
    int  i, loop;

    BYTE octave = 48;
    BYTE szMusKey[25] = { 0x5A,0x53,0x58,0x44,0x43,0x56,0x47,0x42,0x48,0x4E,0x4A,0x4D, 0x51 , 0x32 , 0x57 , 0x33 , 0x45 , 0x52 , 0x35 , 0x54 , 0x36 , 0x59 , 0x37 , 0x55 , 0x49};
    //                      z   s   x      d   c    v    g   b    h    n    j     m     q      2     w     3      e     r      5     t       6       y       7   u       i
    BYTE szMusKeyOnOff[25] = { 0 };
    BYTE ins = 7;
    BYTE vol = 100;

    m_DevHandle = Midi_Open(0);

    if (m_DevHandle == NULL)
    {
        return;
    }

    textcolor(WHITE, BLUE);
    printf("[ESC] : Á¾·á   [Arrow Up] : ¿ÁÅ¸ºê ¿Ã¸²   [Arrow Down] : ¿ÁÅ¸ºê ³»¸²       \n[Arrow Right] : ¾Ç±â ¹øÈ£ ¿Ã¸²   [Arrow Left] : ¾Ç±â ¹øÈ£ ³»¸²             \n[NUMPAD 2] : º¼·ý ³»¸²   [NUMPAD 8] : º¼·ý ¿Ã¸² [ENTER] : ¸ðµç ¼Ò¸® ÁßÁö   \n\n");
    textcolor(BLACK, WHITE);
    printf("¦£¦¡¦¡¦¡¦¨¦¡¦¡¦¡¦¨¦¡¦¨¦¡¦¡¦¡¦¨¦¡¦¡¦¡¦¨¦¡¦¡¦¡¦¨¦¡¦¡¦¡¦¨¦¡¦¨¦¡¦¡¦¡¦¨¦¡¦¨¦¡¦¡¦¡¦¨¦¡¦¡¦¡¦¨¦¡¦¡¦¡¦¨¦¡¦¡¦¡¦¨¦¡¦¨¦¡¦¡¦¡¦¨¦¡¦¡¦¡¦¨¦¡¦¡¦¡¦¨¦¡¦¡¦¡¦¨¦¡¦¨¦¡¦¡¦¡¦¨¦¡¦¨¦¡¦¡¦¡¦¨¦¡¦¡¦¡¦¨¦¡¦¡¦¡¦¡¦¡¦¤ \n");
    printf("¦¢   ¦¢   ¦¢ ¦¢   ¦¢   ¦¢   ¦¢   ¦¢ ¦¢   ¦¢ ¦¢   ¦¢   ¦¢   ¦¢   ¦¢ ¦¢   ¦¢   ¦¢   ¦¢   ¦¢ ¦¢   ¦¢ ¦¢   ¦¢   ¦¢     ¦¢ \n");
    printf("¦¢   ¦¢ S ¦¢ ¦¢ D ¦¢   ¦¢   ¦¢ G ¦¢ ¦¢ H ¦¢ ¦¢ J ¦¢   ¦¢   ¦¢ 2 ¦¢ ¦¢ 3 ¦¢   ¦¢   ¦¢ 5 ¦¢ ¦¢ 6 ¦¢ ¦¢ 7 ¦¢   ¦¢     ¦¢ \n");
    printf("¦¢   ¦¦¦¡¦¨¦¡¦¥ ¦¦¦¡¦¨¦¡¦¥   ¦¢   ¦¦¦¡¦¨¦¡¦¥ ¦¦¦¡¦¨¦¡¦¥ ¦¦¦¡¦¨¦¡¦¥   ¦¢   ¦¦¦¡¦¨¦¡¦¥ ¦¦¦¡¦¨¦¡¦¥   ¦¢   ¦¦¦¡¦¨¦¡¦¥ ¦¦¦¡¦¨¦¡¦¥ ¦¦¦¡¦¨¦¡¦¥   ¦¢     ¦¢ \n");
    printf("¦¢  Z  ¦¢  X  ¦¢  C  ¦¢  V  ¦¢  B  ¦¢  N  ¦¢  M  ¦¢  Q  ¦¢  W  ¦¢  E  ¦¢  R  ¦¢  T  ¦¢  Y  ¦¢  U  ¦¢  I  ¦¢ \n");
    printf("¦¦¦¡¦¡¦¡¦¡¦¡¦ª¦¡¦¡¦¡¦¡¦¡¦ª¦¡¦¡¦¡¦¡¦¡¦ª¦¡¦¡¦¡¦¡¦¡¦ª¦¡¦¡¦¡¦¡¦¡¦ª¦¡¦¡¦¡¦¡¦¡¦ª¦¡¦¡¦¡¦¡¦¡¦ª¦¡¦¡¦¡¦¡¦¡¦ª¦¡¦¡¦¡¦¡¦¡¦ª¦¡¦¡¦¡¦¡¦¡¦ª¦¡¦¡¦¡¦¡¦¡¦ª¦¡¦¡¦¡¦¡¦¡¦ª¦¡¦¡¦¡¦¡¦¡¦ª¦¡¦¡¦¡¦¡¦¡¦ª¦¡¦¡¦¡¦¡¦¡¦¥ \n");
    textcolor(LIGHTGRAY, BLACK);
    gotoxy(0, 12);

    printf("Octave : %d   ", octave / 12 - 2);
    gotoxy(13, 12);
    printf("Instrument Number : %d   ", ins);
    gotoxy(39, 12);
    printf("Volume : %d   ", vol);

    Midi_AllChannelSoundOff(m_DevHandle);
    Midi_SendShortMsg(m_DevHandle, 0xB0, 7, vol);



    loop = 1;

    while (loop)
    {
        if (_kbhit())
        {
            if (GetKeyState(VK_ESCAPE) & 0xFF00) loop = 0;
            else if (GetKeyState(VK_UP) & 0xFF00) {
                if (octave + 12 < 109 - 12) octave += 12;
                gotoxy(0, 12);
                printf("Octave : %d  ", octave / 12 - 2);
                Sleep(170);
            }
            else if (GetKeyState(VK_DOWN) & 0xFF00) {
                if (octave - 12 > 12)octave -= 12;
                gotoxy(0, 12);
                printf("Octave : %d  ", octave / 12 - 2);
                Sleep(170);
            }
            else if (GetKeyState(VK_LEFT) & 0xFF00) {
                if (ins - 1 > -1) {
                    ins--;
                }
                gotoxy(13, 12.);
                printf("Instrument Number : %d   ", ins);
                Midi_SendShortMsg(m_DevHandle, 0xC0, ins, 0);
                Sleep(125);
            }
            else if (GetKeyState(VK_RIGHT) & 0xFF00) {
                if (ins + 1 < 127) {
                    ins++;
                }
                gotoxy(13, 12.);
                printf("Instrument Number : %d   ", ins);
                Midi_SendShortMsg(m_DevHandle, 0xC0, ins, 0);
                Sleep(125);
            }
            else if (GetKeyState(VK_NUMPAD2) & 0xFF00) {
                if (vol - 1 > -1) {
                    vol--;
                }
                gotoxy(39, 12.);
                printf("Volume : %d   ", vol);
                Sleep(125);
            }
            else if (GetKeyState(VK_NUMPAD8) & 0xFF00) {
                if (vol + 1 < 101) {
                    vol++;
                }
                gotoxy(39, 12.);
                printf("Volume : %d   ", vol);
                Sleep(125);
            }
            else if (GetKeyState(VK_RETURN) & 0xFF00) {
                Midi_AllChannelSoundOff(m_DevHandle);
            }
            else {
                for (i = 0; i < 25; i++)
                {
                    if (GetKeyState(szMusKey[i]) & 0xFF00)
                    {
                        if (szMusKeyOnOff[i] == 0)
                        {
                            szMusKeyOnOff[i] = 1;
                            Midi_SendShortMsg(m_DevHandle, 0x90, (BYTE)(i + octave), vol);
                            gotoxy(4 * (i + 1), 10);
                            printNemo(i , false);
                        }
                    }
                }
            }
        }

        for (i = 0; i < 25; i++)
        {
            if (!(GetKeyState(szMusKey[i]) & 0xFF00))
            {
                if (szMusKeyOnOff[i] != 0)
                {
                    szMusKeyOnOff[i] = 0;
                    Midi_SendShortMsg(m_DevHandle, 0x80, (BYTE)(i + octave), vol);
                    printNemo(i, true);
                }
            }
        }
    }

    for (i = 0; i < 25; i++)
    {
        if (szMusKeyOnOff[i] != 0)
        {
            Midi_SendShortMsg(m_DevHandle, 0x80, (BYTE)(i + octave), vol);
            printNemo(i, true);
        }
    }

    Midi_AllChannelSoundOff(m_DevHandle);
    Midi_Close(m_DevHandle);
}