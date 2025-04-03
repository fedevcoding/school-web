const RANDOM_ID_URL =
  "https://it.wikipedia.org/w/api.php?action=query&list=random&rnlimit=1&rnnamespace=0&format=json&origin=*";

const POST_DATA_URL =
  "https://it.wikipedia.org/w/api.php?action=query&prop=extracts&explaintext&exintro&format=json&origin=*&pageids=";

const genBtn = document.getElementById("generate-btn");
const cancelBtn = document.getElementById("cancel-btn");
const container = document.querySelector(".container");
const loader = document.querySelector(".loader");
const btnInfo = document.querySelector(".btn-info");

async function getRandomId() {
  try {
    const res = await fetch(RANDOM_ID_URL);
    const data = await res.json();
    if (res.status === 200) {
      const id = data?.query?.random?.[0]?.id;
      if (id) return { err: null, id };
    }

    return { err: new Error("Something went wrong"), id: null };
  } catch (err) {
    return { err, res: null };
  }
}

async function getPostInfo(id) {
  try {
    const res = await fetch(POST_DATA_URL + id);
    const data = await res.json();

    if (res.status === 200) {
      const postInfo = data?.query?.pages?.[id];
      return { err: null, postInfo };
    }

    return { err: new Error("Something went wrong"), id: null };
  } catch (err) {
    return { err, res: null };
  }
}

let generating = false;

genBtn.addEventListener("click", async () => {
  if (generating) return;
  generating = true;

  loader.classList.remove("hide");
  btnInfo.classList.add("hide");

  const { id, err } = await getRandomId();
  if (err) {
    alert("Something went wrong getting random post");
  }
  const { postInfo, err: err2 } = await getPostInfo(id);
  if (err2) {
    alert("Something went wrong getting post info");
  }

  loader.classList.add("hide");
  btnInfo.classList.remove("hide");

  const { extract, title } = postInfo;

  container.innerHTML += `
  <article>
  <h3>${title}</h3>
  <p>${extract}</p>
    </article>`;
  generating = false;
});

cancelBtn.addEventListener("click", () => {
  container.innerHTML = "";
});
