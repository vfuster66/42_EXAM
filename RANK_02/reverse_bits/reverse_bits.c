unsigned char	reverse_bits(unsigned char octet)
{
	int	i = 0;
	int	reversed = 0;

	while (i < 8)
	{
		reversed = (reversed << 1) | (octet & 1);
		octet >>= 1;
		i++;
	}
	return (reversed);
}
