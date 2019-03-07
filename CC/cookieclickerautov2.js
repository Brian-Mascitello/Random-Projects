// http://orteil.dashnet.org/cookieclicker/

// Big Cookie
bigCookie.addEventListener('click', Game.ClickCookie);
setInterval(function () {
  bigCookie.click();
}, 1);

// Golden Cookie
setInterval(function () {
  if (Game.goldenCookie !== undefined) {
    Game.goldenCookie.click();
  }
}, 2000);

// Reindeer
setInterval(function () {
  if (Game.seasonPopup !== undefined) {
    Game.seasonPopup.click();
  }
}, 3500);

// Upgrades
upgrades = $('#upgrades')

setInterval(function () {
  if (upgrades.firstChild !== null) {
    if (upgrades.firstChild.classList.contains('enabled')) {
      upgrades.firstChild.click();
    }
  }
}, 500);

// Products
cursor = $('#product0');
grandma = $('#product1');
farm = $('#product2');
mine = $('#product3');
factory = $('#product4');
bank = $('#product5');
temple = $('#product6');
wizard = $('#product7');
shipment = $('#product8');
alchemy = $('#product9');
portal = $('#product10');
time = $('#product11');
antimatter = $('#product12');
prism = $('#product13');
chancemaker = $('#product14');
fractal = $('#product15');

setInterval(function () {
  if (fractal.classList.contains('enabled')) {
    fractal.click();
  } else if (chancemaker.classList.contains('enabled')) {
    chancemaker.click();
  } else if (prism.classList.contains('enabled')) {
    prism.click();
  } else if (antimatter.classList.contains('enabled')) {
    antimatter.click();
  } else if (time.classList.contains('enabled')) {
    time.click();
  } else if (portal.classList.contains('enabled')) {
    portal.click();
  } else if (alchemy.classList.contains('enabled')) {
    alchemy.click();
  } else if (shipment.classList.contains('enabled')) {
    shipment.click();
  } else if (wizard.classList.contains('enabled')) {
    wizard.click();
  } else if (temple.classList.contains('enabled')) {
    temple.click();
  } else if (bank.classList.contains('enabled')) {
    bank.click();
  } else if (factory.classList.contains('enabled')) {
    factory.click();
  } else if (mine.classList.contains('enabled')) {
    mine.click();
  } else if (farm.classList.contains('enabled')) {
    farm.click();
  } else if (grandma.classList.contains('enabled')) {
    grandma.click();
  } else if (cursor.classList.contains('enabled')) {
    cursor.click();
  }
}, 750);

// Notes
setInterval(function () {
  if (notes.childElementCount > 0) {
    if (notes.childElementCount < 2) {
      notes.children[0].children[0].click();
    } else {
      notes.children[1].children[0].click();
    }
  }
}, 3000);