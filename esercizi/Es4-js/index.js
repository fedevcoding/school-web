const back = document.getElementById('back');
const forward = document.getElementById('forward');
const stop = document.getElementById('stop');
const start = document.getElementById('start');
const img = document.getElementById('img');
const imgDesc = document.getElementById('desc');

const images = [
    "amin.jpg",
    "dimitri.jpg",
    "grace.jpg",
    "levi.jpg",
    "mahdi.jpg",
    "michiel.jpg",
    "mono.jpg",
    "nicolai.jpg",
    "sarah.jpg"
];

let index = 0;

back.addEventListener('click', () => {
    index--;
    if (index < 0) index = images.length - 1;
    img.src = "./img/" + images[index];
    imgDesc.innerHTML = images[index];
})

forward.addEventListener('click', () => {
    index++;
    if (index >= images.length) index = 0;
    img.src = "./img/" + images[index];
    imgDesc.innerHTML = images[index];
})

let interval = null;

start.addEventListener('click', () => {
    interval = setInterval(() => {
        index++;
        if (index >= images.length) index = 0;
        img.src = "./img/" + images[index];
    }, 2000)
})

stop.addEventListener('click', () => {
    clearInterval(interval);
})