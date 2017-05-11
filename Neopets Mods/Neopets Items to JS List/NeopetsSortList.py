raw_path = r'C:\Users\Brian\Downloads\attachments\RAW ITEMS.txt'

fixed_path = raw_path.replace('\\', '/')

with open(fixed_path) as file:
    content = file.readlines()

content = [item.strip() for item in content]

content.sort()

js_list = '" . ' + ' . '.join(content) + ' . ";'

print('\nJS List of Items:\n\n' + js_list)
