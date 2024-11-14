const throwDice = document.getElementById("throw")
const stopDice = document.getElementById("stop")
const dices = document.getElementById("dices")

let int;
let count = 0;

function addDice(){
    const dice = document.createElement("img")
    dice.src = "./images/" + (Math.floor(Math.random() * 6) + 1) + ".png";
    console.log(dice.src)
    dices.appendChild(dice)
    count++;
}

throwDice.addEventListener("click", () => {
    int = setInterval(addDice, 2000)
});

stopDice.addEventListener("click", () => {
    
    alert("You generated " + count + " dices")
    count = 0;
    clearInterval(int)
})