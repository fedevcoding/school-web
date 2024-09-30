function add() {
    const num1 = document.getElementById("num1").value;
    const num2 = document.getElementById("num2").value;
    const result = parseInt(num1) + parseInt(num2);
    document.getElementById("res").innerHTML = result;
}

const btn = document.getElementById("btn");

btn.addEventListener("click", add);