# Bijus Browser

- This project will have a special place in my heart since it's the first project I've written that has 
a real usage starting from simple problems.

## Main usage

- The program is a **terminal GUI browser** and it contains some features including *filtering* and *easy html to text translation*

## Instalation

Use the following in the terminal: 

```
git clone https://github.com/RaresCroicia/Bijus_browser
cd Bijus_browser
make prerequisite
make
./browser
```

## Filtering

- When searching for whatever you want, you have to insert at least one word that you want to search, and then you have to press
either A or S. S comes from **Simple** filtering and A from **Advanced** filtering

### Simple filtering

- When using the *simple* filtering, all you can do is search for words in websites. For example, if you type: hello world, you will be shown the websites containing
at least one of the 2 words

### Advanced filtering

- When using the *advanced* filtering, you can do **two** more types of filtering

#### Not containing the word

- When using the **-** character before any word, the filter will search for every website not containing the word

#### Searching for a whole sequence

- When you want to search for a sequence, you can type it between **"** *sequence* **"** and the filter will search only for websites containing that exact sequence

#### Combining the elements

- You can also combine every single filtering type, so for example, let's say you type:

```
    Welcome "to the board" -here
```

- This search will give you every website that:
    - contains the word "Welcome"
    - contains the sequence "to the board"
    - does not contain the word "here"

### Also a little sort

- The websites you'll be shown are sorted in alphabetical order and based on the visits count

## Key Usage

### Q

- Mainly, almost everytime you press **Q**, the browser will *close*, the exception being when typing in the searchbar.

### B

- Mainly, almost everytime you press **B**, the browser will *go back one page*, the exception being when typing in the searchbar.

### C

- This button has a one time usage, pressing **C** in the first page of the browser will get you to the search bar page.

### S and A

- These buttons' usage has been described above, so just as a recap, after typing what you want to search and pressing enter, the **S** button will get you a *simple* filtered result, while
pressing **A** will get you an *advanced* filtered result.
