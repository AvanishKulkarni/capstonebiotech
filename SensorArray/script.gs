function main() {
  var sprsheet = SpreadsheetApp.getActiveSpreadsheet();
  var sheet = sprsheet.getSheetByName("Sheet1");
 
  for (var lastRow = 378; lastRow < 464; lastRow++) {
    var inputRow = ("A" + lastRow);
    var outputRow = ("B" + lastRow + ":D" + lastRow);
 
    var string = sheet.getRange(inputRow).getValue();
 
    console.log(string);
    
    var json = JSON.parse(string);
 
    sheet.getRange(outputRow).setValues([[json["airwet"], json["temp"], json["soilwet"]]]);
  }
}