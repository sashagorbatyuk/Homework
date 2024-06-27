# Завдання 3
# Є деякий текст. Порахуйте в цьому тексті кількість речень і виведіть на екран отриманий результат.

def get_count_sentences(text):
    sentences = text.split('.')
    filteredSentences = list(filter(None, sentences))
    return len(filteredSentences)

user_text = input("Введіть текст: ")

sentences_count = get_count_sentences(user_text)

print("Кількість речень у тексті:", sentences_count)