ALPHABET = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'


def vigenere_encrypt(plain_text, key):

	plain_text = plain_text.upper()
	key = key.upper()

	cipher_text = ''
	key_index = 0
	
	for character in plain_text:
		if character == ' ':
			cipher_text = cipher_text + ' '
		else:
			index = (ALPHABET.find(character)+(ALPHABET.find(key[key_index])))%len(ALPHABET)
			cipher_text += ALPHABET[index]
			key_index = key_index + 1
		if key_index == len(key):
			key_index = 0

	return cipher_text


def vigenere_decrypt(cipher_text, key):

	cipher_text = cipher_text.upper()
	key = key.upper()

	plain_text = ''
	key_index = 0

	for character in cipher_text:
		if character == ' ':
			plain_text += ' '
		else :
			index = (ALPHABET.find(character)-(ALPHABET.find(key[key_index])))%len(ALPHABET)
			plain_text += ALPHABET[index]
			key_index = key_index + 1

		if key_index == len(key):
			key_index = 0

	return plain_text

if __name__ == "__main__":

	n = int(input("enter 1 to decrypt and 0 to encrypt: "))
	if n == 0 :
		plain_text = raw_input("enter message to encode: ")
		encrypted = vigenere_encrypt(plain_text,'table')
		print('Encrypted message: %s' % encrypted)
	else:
		enc_msg = raw_input("enter message to decode: ")
		decrypted = vigenere_decrypt(enc_msg,'table')
		print('Decrypted mesage: %s' % decrypted)
