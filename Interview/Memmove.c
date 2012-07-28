/* Strcpy.c */

char* my_strcpy(char* dst, const char* src) {
	assert((dst == NULL) || (src == NULL))
	char* dst_tmp = dst;
	char* src_tmp = src;
	while((*dst_tmp++ = *src_tmp++) != '\0') {}
	return dst;
}

char* my_strncpy(char* dst, const char* src, size_t n) {
	assert((dst == NULL) || (src == NULL))
	char* dst_tmp = dst;
	char* src_tmp = src;
	int i;
	for(i = 0; (i < n) && (src[i] != '\0'); ++i)
		dst_tmp[i] = src_tmp[i];
	for(; i < n; ++i)
		dst_tmp[i] = '\0';
	return dst;
}


void* my_memcpy(char* dst, const char* src, int len) {
	assert((dst == NULL) || (src == NULL));
	char* dst_tmp = dst;
	char* src_tmp = src;
	while(len --) 
		*dst_tmp++ = *src_tmp++;

	return dst;
}

void* my_memmove(char* dst, const char* src, int len) {
	assert((dst == NULL) || (src == NULL));
	char* dst_tmp = dst;
	char* src_tmp = src;

	if((dst <= src) || (src + len < dst))
		while(len--)
			*dst_tmp++ = *src_tmp++;
	else {
		src_tmp += len - 1;
		dst_tmp += len - 1;
		while(len--)
			*--dst_tmp = *--src_tmp;
	}
	return dst;
}

int main(void)
{
	char buf[10];
	char buf2[10] = "abcdefghij";
	char buf3[5] = "hello";
	my_strcpy(buf, "hello!");
}
