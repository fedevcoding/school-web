function searchProduct() {
    const val = document.getElementById("search-product")?.value;
    if (!val) return

    window.open(`https://tech-tools.fedev.me/?search=${val}`);
}