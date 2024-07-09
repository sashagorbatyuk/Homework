# 1 Напиши код, який приймає рядок тексту і створює словник, де ключами є символи, а значеннями — кількість їх появ у тексті
def char_count(text):
    count_dict = {}
    for char in text:
        if char in count_dict:
            count_dict[char] += 1
        else:
            count_dict[char] = 1
    return count_dict

text = "example text"
result = char_count(text)
print(result)