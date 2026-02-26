#include <stdio.h>
#include <locale.h>
#include <wchar.h>

int main()
{
    // using string format
	wchar_t hello[] = L"Hello world\n\0"; // complier inteprets its as wide characters cuz of L

	/* first, set the locale */
    setlocale(LC_ALL,"en_US.UTF-8");

    fputws(hello,stdout); // file stream redirection
    wprintf(L"%ls", hello); // L"" compiler treat it as a widecharacter string
    return 0;
}
