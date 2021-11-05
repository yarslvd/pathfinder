#include "../inc/libmx.h"

static int count_letters(const char *s, char c){
	int i = 0;
	while(s[i] != c && s[i]){
		i++;
	}
	return i;
}

char **mx_strsplit(char const *s, char c) {
	char **buff = NULL;

	if (!s) {
		return NULL;
	}
	
	int word_count = mx_count_words(s, c);
	buff = (char **)malloc(8 * (word_count + 1));
	int word_len = 0;
	int i = 0;

	while((*s) && (*s != '\0')){
		if(*s != c) {
			word_len = count_letters(s, c);
			buff[i] = mx_strndup(s, word_len);
			s += word_len;
			i++;
			continue;
		}
		s++;
	}
	buff[i] = NULL;

	return buff;
}
