favourite_language = {
    'jen':'python',
    'sarah':'c',
    'edward':'rust',
    'phil':'python',
    'john':'java',
}
#for key,value in favourite_language.items():
 #   print(f"{key.title()}:{value}")
friends = ['phil','sarah']
for name in favourite_language.keys():
    print(f"Hi! {name.title()}.")
    if name in friends:
        language = favourite_language[name].title()
        print(f"\t{name.title()},I see you love to {language}!")