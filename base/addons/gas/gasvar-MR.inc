
* Will be replaced by more consistent input data.
PARAMETER
            DG_NGF_VAR(gasanvendelser,SSS,TTT)
;

PARAMETER DG_VAR(gasanvendelser,AAA,SSS,TTT)
/
$ondelim
$include '../../base/addons/gas/gasforbrug.csv';
$offdelim
/;

DGRES_VAR(AAA,SSS,TTT) = DG_VAR('residual',AAA,SSS,TTT);
DGOTH_VAR(AAA,SSS,TTT) = DG_VAR('Andre timeafl�ste',AAA,SSS,TTT)
                         +DG_VAR('Industriel andet form�l',AAA,SSS,TTT);


execute_load '../../base/addons/gas/gasforbrug.gdx', DG_NGF_VAR;

DGRES_VAR(AAA,SSS,TTT)$DDDNODE('NGF',AAA) = DG_NGF_VAR('residual',SSS,TTT);
DGOTH_VAR(AAA,SSS,TTT)$DDDNODE('NGF',AAA) = DG_NGF_VAR('Andre timeafl�ste',SSS,TTT)
                                                    +DG_NGF_VAR('Industriel andet form�l',SSS,TTT);
