# 5 Напиши код, який приймає словник і рядок, і повертає список ключів, значення яких містять даний рядок.
def find_keys_with_substring(input_dict, substring):
    keys_with_substring = []
    for key, value in input_dict.items():
        if substring in value:
            keys_with_substring.append(key)
    return keys_with_substring

input_dict = {
    'key1': 'this is a test',
    'key2': 'another example',
    'key3': 'test case',
    'key4': 'example in'
}
substring = 'example'
result = find_keys_with_substring(input_dict, substring)
print(result)