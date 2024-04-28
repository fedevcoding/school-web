document.querySelector("main").style.height = (window.innerHeight - document.getElementById("header").offsetHeight) + "px";

const typed = new Typed("#typed", {
    strings: ["Keyboards.", "Headphones.", "Chargers.", "Smart watches."],
    startDelay: 100,
    typeSpeed: 80,
    backSpeed: 60,
    backDelay: 80,
    loop: true,
});