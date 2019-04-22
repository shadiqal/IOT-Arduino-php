loadDataSensor();

function setVariabel(batas) {

  $.ajax({
    url: '../php/simpanConfig.php',
    type: 'POST',
    data: {
      batas: batas
    }

  }).done(function (data) {

  });
  $('#notifBatas').modal('show');
  setInterval(function () {
    $('#notifBatas').modal('hide');
  }, 10000);
}

function loadDataSensor(batas) {

  setInterval(function () {

    $.ajax({
      url: '../php/data.php',
      type: 'POST',

    }).done(function (data) {
      console.log(data);
      var data2 = data.split("|");
      var berat = data2[0];
      var waktu = data2[1];
      var id = data2[2];
      var batas = data2[3];
      $('#berat').text(berat);
      $('#waktu').text(waktu);
      if (Number(berat) > Number(batas)) {
        $('#pesan').show();
        $('#pesan').text("berat muatan overload");
      } else {
        $('#pesan').hide();
      }
    })
  }, 500);
}

function loadModal() {
  $.ajax({
    url: '../php/allData.php',
    type: 'POST',
  }).done(function (data) {
    $('#dataLogging').html(data);
  });
}