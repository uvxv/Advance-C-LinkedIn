#include <stdio.h>
#include <locale.h>

/*
 - The cahracter sets like currency symbols, UTC which may differ from country to country is known as locale
*/
int main()
{
    struct lconv *locale_ptr;
	char *locale;

	locale = setlocale(LC_ALL,"");
	printf("The current locale is %s\n",locale);

    locale_ptr = localeconv();

    printf("Decimal point: %s\n",locale_ptr->decimal_point);
    printf("Thousands separator: %s\n",locale_ptr->thousands_sep);
    printf("Currency symbol: %s\n",locale_ptr->currency_symbol);

    return(0);
}
