const addBtn = document.querySelector("#aggiungi");
const inputVoto = document.querySelector("#voto");
const mediaVoti = document.querySelector("#media-voti");
const listaVoti = document.querySelector("#lista-voti");

let media = 0;
let voti = 0;

addBtn.addEventListener("click", () => {
  const voto = parseInt(inputVoto.value);

  const li = document.createElement("li");
  li.textContent = voto;
  listaVoti.appendChild(li);

  inputVoto.value = "";

  media = Math.round(((media + voto) / ++voti) * 10) / 10;

  mediaVoti.textContent = media;
});
