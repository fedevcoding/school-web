const input = document.getElementById('input');
const add = document.getElementById('add');
const order = document.getElementById('order');
const list = document.getElementById('nomi');

let names = [];

add.addEventListener('click', () => {
    const val = input.value;
    if (val.trim() === '') {
        alert('Inserisci un nome');
        return;
    }
    const li = document.createElement('li');
    li.textContent = val;
    list.appendChild(li);
    names.push(val);
    input.value = '';
})

order.addEventListener('click', () => {
    names.sort();
    list.innerHTML = '';
    names.forEach(name => {
        const li = document.createElement('li');
        li.textContent = name;
        list.appendChild(li);
    })
})