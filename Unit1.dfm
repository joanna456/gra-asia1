object Form1: TForm1
  Left = 225
  Top = 75
  Width = 1016
  Height = 636
  Caption = 'e'
  Color = clMedGray
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnActivate = FormActivate
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object EtykietaPunktow: TLabel
    Left = 32
    Top = 4
    Width = 91
    Height = 29
    Caption = 'Punkty: 0'
    Color = clMedGray
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -21
    Font.Name = 'Comic Sans MS'
    Font.Style = []
    ParentColor = False
    ParentFont = False
  end
  object EtykietaPoziomu: TLabel
    Left = 864
    Top = 4
    Width = 87
    Height = 29
    Caption = 'Poziom: 1'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -21
    Font.Name = 'Comic Sans MS'
    Font.Style = []
    ParentFont = False
  end
  object PrzyciskKontroli: TLabel
    Left = 0
    Top = 552
    Width = 993
    Height = 40
    Cursor = crHandPoint
    Alignment = taCenter
    AutoSize = False
    Caption = 'Rozpocznij Gr'#281'!'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindow
    Font.Height = -29
    Font.Name = 'Comic Sans MS'
    Font.Style = []
    ParentFont = False
  end
  object Panel1: TPanel
    Left = 0
    Top = 41
    Width = 1000
    Height = 507
    TabOrder = 0
  end
end
