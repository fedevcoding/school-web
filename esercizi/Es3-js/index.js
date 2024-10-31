const result = document.getElementById("result");
const numGeneratoInfo = document.getElementById("num-generato-info");
const button = document.getElementById("button");
const confirmBtn = document.getElementById("conferma-btn");
const input = document.getElementById("input");

let num;

button.addEventListener("click", () => {
  num = Math.floor(Math.random() * 100) + 1;
  result.textContent = "";
  numGeneratoInfo.textContent = `Il numero è stato generato`;
});

confirmBtn.addEventListener("click", () => {
  if (!num) {
    result.textContent = "Devi prima generare un numero!";
    return;
  }

  const inputNum = parseInt(input.value);
  if (inputNum === num) {
    result.textContent = "Hai indovinato!";
    num = undefined;
  } else {
    if (inputNum > num) {
      result.textContent = "Il numero è troppo alto!";
    } else {
      result.textContent = "Il numero è troppo basso!";
    }
  }
});
