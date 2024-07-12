# Напишіть функцію, яка відобразить на екрані такий форматований текст:
# "Don't compare yourself with anyone in this world…
# if you do so, you are insulting yourself."
# Bill Gates

class bcolors:
    DEFAULT = '\033[0m'
    DARK_GRAY = '\033[90m'
    RED = '\033[31m'

def display_quote():
    quote = bcolors.DARK_GRAY + '"Don\'t compare yourself with anyone in this world…\n'
    quote += bcolors.RED + "if " + bcolors.DEFAULT + "you " + bcolors.RED + "do so" + bcolors.DEFAULT + ", you are insulting yourself." + bcolors.DARK_GRAY + '"\n' + bcolors.DEFAULT
    quote += "Bill Gates"
    print(quote)

display_quote()