document.getElementById("search-form")?.addEventListener("submit", e => {
    e.preventDefault();
    const val = document.getElementById("search-product")?.value;
    if (!val) return
    window.open(`https://tech-tools.fedev.me/?search=${val}`);
});


const typed = new Typed("#typed", {
    strings: ["Keyboards.", "Headphones.", "Chargers.", "Smart watches."],
    startDelay: 100,
    typeSpeed: 80,
    backSpeed: 60,
    backDelay: 80,
    loop: true,
});