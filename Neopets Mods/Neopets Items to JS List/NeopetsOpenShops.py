raw_path = r'C:\Users\Brian\Downloads\attachments\WITH SHOP NAMES.txt'

fixed_path = raw_path.replace('\\', '/')

with open(fixed_path) as file:
    content = file.readlines()

websites = []

for string in content:
    if string.startswith('http'):
        if string.endswith('\n'):
            string = string[0:-1]
        websites.append(string)

websites.sort()

for site in websites:
    print(site)

