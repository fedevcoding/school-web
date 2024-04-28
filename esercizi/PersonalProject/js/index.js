const CURRENT_YEAR = new Date().getFullYear();
const TECH_TOOLS_URL = "https://tech-tools.fedev.me"


document.getElementById("search-form")?.addEventListener("submit", e => {
    e.preventDefault();
    const val = document.getElementById("search-product")?.value;
    if (!val) return
    window.open(`${TECH_TOOLS_URL}/?search=${val}`);
});


document.querySelectorAll(".curr-year")?.forEach((el) => {
    el.textContent = CURRENT_YEAR;
})

document.querySelector("main").style.height = (window.innerHeight - document.getElementById("header").offsetHeight) + "px";

const typed = new Typed("#typed", {
    strings: ["Keyboards.", "Headphones.", "Chargers.", "Smart watches."],
    startDelay: 100,
    typeSpeed: 80,
    backSpeed: 60,
    backDelay: 80,
    loop: true,
});