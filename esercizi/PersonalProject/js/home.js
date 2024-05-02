const typed = new Typed("#typed", {
    strings: ["Keyboards.", "Headphones.", "Chargers.", "Smart watches."],
    startDelay: 100,
    typeSpeed: 80,
    backSpeed: 60,
    backDelay: 80,
    loop: true,
});

const element = document.querySelector("#tilt");
VanillaTilt.init(element);
