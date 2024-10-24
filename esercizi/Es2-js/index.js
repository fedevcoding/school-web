const btn = document.querySelector("#submit");
const input = document.querySelector("#number");
const nums = document.querySelector("#nums");

btn.addEventListener("click", () => {
  nums.innerHTML = "";
  const val = parseInt(input.value);

  const divisori = [];

  for (let i = val; i >= 0; i--) {
    if ((val / i) % 1 === 0) {
      divisori.push(i);
    }
  }

  divisori.forEach(div => {
    const divElem = document.createElement("li");
    divElem.innerHTML = div;
    nums.appendChild(divElem);
  });
});
