// Двоичный логарифм

size_t log2(size_t n)
{
	short pos = 63;
	while (!((size_t(1) << pos) & n) && pos != 0) --pos;
	return pos;
}
