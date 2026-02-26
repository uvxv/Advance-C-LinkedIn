#include <locale.h>
#include <wchar.h>
#include <stdio.h>

#define SAD 0x1f641
#define HAPPY 0x1f600
#define MEH 0x1f610
#define HUH 0x1f914

int main()
{
	wchar_t mood[3] = {SAD, HAPPY, MEH};
	wchar_t *moodstr[3] = {L"sad", L"happy", L"meh"};
	int looper;
	wint_t wide_char;

	// set locale
	setlocale(LC_ALL, "en_US.UTF-8");

	//message
	wprintf(L"What is your mood?\n");
	for(looper = 0; looper<3 ; looper++ ){
		wprintf(L"%d: %lc %ls\n", looper+1 , mood[looper], moodstr[looper]);
	}
	
	wprintf(L"Choice: ");
	wide_char = getwchar();

	switch (wide_char)
	{
	case '1':
		wprintf(L"%lc Sad\n", SAD);
		break;
	
	case '2':
		wprintf(L"%lc Happy\n", HAPPY);
		break;

	case '3':
		wprintf(L"%lc Meh\n", MEH);
		break;

	default:
		wprintf(L"%lc Huh\n", HUH);
		break;
	}
	return 0;
}
