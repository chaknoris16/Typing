#include "text_for_print_json.h"

text_for_print_json::text_for_print_json(QObject *parent)
    : QObject{parent}
{

}
void text_for_print_json::setJsonFile(){
    // exercises_ms_Tiny_wordsArray.append("");
    exercises_ms_Tiny_wordsArray.append("allot allot allot allot allot allot allot allot allot allot");
    exercises_ms_Tiny_wordsArray.append("enemy enemy enemy enemy enemy enemy enemy enemy enemy enemy");
    exercises_ms_Tiny_wordsArray.append("fifty fifty fifty fifty fifty fifty fifty fifty fifty fifty");
    exercises_ms_Tiny_wordsArray.append("forty forty forty forty forty forty forty forty forty forty");
    exercises_ms_Tiny_wordsArray.append("guard guard guard guard guard guard guard guard guard guard");
    exercises_ms_Tiny_wordsArray.append("judge judge judge judge judge judge judge judge judge judge");
    exercises_ms_Tiny_wordsArray.append("kneel kneel kneel kneel kneel kneel kneel kneel kneel kneel");
    exercises_ms_Tiny_wordsArray.append("laser laser laser laser laser laser laser laser laser laser");
    exercises_ms_Tiny_wordsArray.append("later later later later later later later later later later");
    exercises_ms_Tiny_wordsArray.append("money money money money money money money money money money");
    exercises_ms_Tiny_wordsArray.append("niece niece niece niece niece niece niece niece niece niece");
    exercises_ms_Tiny_wordsArray.append("ninth ninth ninth ninth ninth ninth ninth ninth ninth ninth");
    exercises_ms_Tiny_wordsArray.append("kneel money niece allot enemy judge guard ninth laser later fifty forty");
    exercises_ms_Tiny_wordsArray.append("judge guard ninth later fifty forty kneel money allot niece laser enemy");

    exercises_ms_Tiny_words2Array.append("piece piece piece piece piece piece piece piece piece piece");
    exercises_ms_Tiny_words2Array.append("queue queue queue queue queue queue queue queue queue queue");
    exercises_ms_Tiny_words2Array.append("sense sense sense sense sense sense sense sense sense sense");
    exercises_ms_Tiny_words2Array.append("siege siege siege siege siege siege siege siege siege siege");
    exercises_ms_Tiny_words2Array.append("their their their their their their their their their their");
    exercises_ms_Tiny_words2Array.append("truly truly truly truly truly truly truly truly truly truly");
    exercises_ms_Tiny_words2Array.append("until until until until until until until until until until");
    exercises_ms_Tiny_words2Array.append("weird weird weird weird weird weird weird weird weird weird");
    exercises_ms_Tiny_words2Array.append("which which which which which which which which which which");
    exercises_ms_Tiny_words2Array.append("which which which which which which which which which which");
    exercises_ms_Tiny_words2Array.append("yacht yacht yacht yacht yacht yacht yacht yacht yacht yacht");
    exercises_ms_Tiny_words2Array.append("young young young young young young young young young young");
    exercises_ms_Tiny_words2Array.append("yacht queue their siege piece which young truly sense width weird until");
    exercises_ms_Tiny_words2Array.append("their width queue siege piece truly weird which young until yacht sense");

    exercises_ms_Small_wordsArray.append("across across across across across across across across across across");
    exercises_ms_Small_wordsArray.append("advice advice advice advice advice advice advice advice advice advice");
    exercises_ms_Small_wordsArray.append("belief belief belief belief belief belief belief belief belief belief");
    exercises_ms_Small_wordsArray.append("column column column column column column column column column column");
    exercises_ms_Small_wordsArray.append("coming coming coming coming coming coming coming coming coming coming");
    exercises_ms_Small_wordsArray.append("dispel dispel dispel dispel dispel dispel dispel dispel dispel dispel");
    exercises_ms_Small_wordsArray.append("easily easily easily easily easily easily easily easily easily easily");
    exercises_ms_Small_wordsArray.append("effect effect effect effect effect effect effect effect effect effect");
    exercises_ms_Small_wordsArray.append("eighth eighth eighth eighth eighth eighth eighth eighth eighth eighth");
    exercises_ms_Small_wordsArray.append("either either either either either either either either either either");
    exercises_ms_Small_wordsArray.append("fourth fourth fourth fourth fourth fourth fourth fourth fourth fourth");
    exercises_ms_Small_wordsArray.append("friend friend friend friend friend friend friend friend friend friend");
    exercises_ms_Small_wordsArray.append("either effect advice friend fourth eighth dispel across belief column easily coming");
    exercises_ms_Small_wordsArray.append("across column coming fourth easily belief advice eighth friend effect dispel either");

    exercises_ms_Small_words2Array.append("genius genius genius genius genius genius genius genius genius genius");
    exercises_ms_Small_words2Array.append("height height height height height height height height height height");
    exercises_ms_Small_words2Array.append("ignore ignore ignore ignore ignore ignore ignore ignore ignore ignore");
    exercises_ms_Small_words2Array.append("innate innate innate innate innate innate innate innate innate innate");
    exercises_ms_Small_words2Array.append("island island island island island island island island island island");
    exercises_ms_Small_words2Array.append("length length length length length length length length length length");
    exercises_ms_Small_words2Array.append("likely likely likely likely likely likely likely likely likely likely");
    exercises_ms_Small_words2Array.append("lovely lovely lovely lovely lovely lovely lovely lovely lovely lovely");
    exercises_ms_Small_words2Array.append("muscle muscle muscle muscle muscle muscle muscle muscle muscle muscle");
    exercises_ms_Small_words2Array.append("ninety ninety ninety ninety ninety ninety ninety ninety ninety ninety");
    exercises_ms_Small_words2Array.append("potato potato potato potato potato potato potato potato potato potato");
    exercises_ms_Small_words2Array.append("prefer prefer prefer prefer prefer prefer prefer prefer prefer prefer");
    exercises_ms_Small_words2Array.append("prefer ignore potato height likely ninety innate length muscle lovely island genius");
    exercises_ms_Small_words2Array.append("genius muscle height prefer lovely likely ninety innate potato length island ignore");

    exercises_ms_Small_words3Array.append("really really really really really really really really really really");
    exercises_ms_Small_words3Array.append("rhythm rhythm rhythm rhythm rhythm rhythm rhythm rhythm rhythm rhythm");
    exercises_ms_Small_words3Array.append("safety safety safety safety safety safety safety safety safety safety");
    exercises_ms_Small_words3Array.append("scared scared scared scared scared scared scared scared scared scared");
    exercises_ms_Small_words3Array.append("speech speech speech speech speech speech speech speech speech speech");
    exercises_ms_Small_words3Array.append("tattoo tattoo tattoo tattoo tattoo tattoo tattoo tattoo tattoo tattoo");
    exercises_ms_Small_words3Array.append("there there there there there there there there there there there there");
    exercises_ms_Small_words3Array.append("tongue tongue tongue tongue tongue tongue tongue tongue tongue tongue");
    exercises_ms_Small_words3Array.append("unique unique unique unique unique unique unique unique unique unique");
    exercises_ms_Small_words3Array.append("vacuum vacuum vacuum vacuum vacuum vacuum vacuum vacuum vacuum vacuum");
    exercises_ms_Small_words3Array.append("vision vision vision vision vision vision vision vision vision vision");
    exercises_ms_Small_words3Array.append("volume volume volume volume volume volume volume volume volume volume");
    exercises_ms_Small_words3Array.append("there tongue really unique vision safety speech rhythm tattoo scared vacuum volume");
    exercises_ms_Small_words3Array.append("really speech vacuum unique there tattoo tongue rhythm scared vision safety volume");

    exercises_ms_Middle_wordsArray.append("absence absence absence absence absence absence absence absence absence absence");
    exercises_ms_Middle_wordsArray.append("achieve achieve achieve achieve achieve achieve achieve achieve achieve achieve");
    exercises_ms_Middle_wordsArray.append("address address address address address address address address address address");
    exercises_ms_Middle_wordsArray.append("amateur amateur amateur amateur amateur amateur amateur amateur amateur amateur");
    exercises_ms_Middle_wordsArray.append("believe believe believe believe believe believe believe believe believe believe");
    exercises_ms_Middle_wordsArray.append("clothes clothes clothes clothes clothes clothes clothes clothes clothes clothes");
    exercises_ms_Middle_wordsArray.append("deceive deceive deceive deceive deceive deceive deceive deceive deceive deceive");
    exercises_ms_Middle_wordsArray.append("dilemma dilemma dilemma dilemma dilemma dilemma dilemma dilemma dilemma dilemma");
    exercises_ms_Middle_wordsArray.append("disease disease disease disease disease disease disease disease disease disease");
    exercises_ms_Middle_wordsArray.append("finally finally finally finally finally finally finally finally finally finally");
    exercises_ms_Middle_wordsArray.append("foreign foreign foreign foreign foreign foreign foreign foreign foreign foreign");
    exercises_ms_Middle_wordsArray.append("forward forward forward forward forward forward forward forward forward forward");
    exercises_ms_Middle_wordsArray.append("disease absence believe clothes deceive achieve dilemma finally amateur address");
    exercises_ms_Middle_wordsArray.append("believe foreign disease deceive finally clothes amateur address forward dilemma");

    exercises_ms_Middle_words2Array.append("further further further further further further further further further further");
    exercises_ms_Middle_words2Array.append("general general general general general general general general general general");
    exercises_ms_Middle_words2Array.append("grammar grammar grammar grammar grammar grammar grammar grammar grammar grammar");
    exercises_ms_Middle_words2Array.append("hamster hamster hamster hamster hamster hamster hamster hamster hamster hamster");
    exercises_ms_Middle_words2Array.append("happily happily happily happily happily happily happily happily happily happily");
    exercises_ms_Middle_words2Array.append("hygiene hygiene hygiene hygiene hygiene hygiene hygiene hygiene hygiene hygiene");
    exercises_ms_Middle_words2Array.append("ideally ideally ideally ideally ideally ideally ideally ideally ideally ideally");
    exercises_ms_Middle_words2Array.append("jealous jealous jealous jealous jealous jealous jealous jealous jealous jealous");
    exercises_ms_Middle_words2Array.append("leisure leisure leisure leisure leisure leisure leisure leisure leisure leisure");
    exercises_ms_Middle_words2Array.append("library library library library library library library library library library");
    exercises_ms_Middle_words2Array.append("married married married married married married married married married married");
    exercises_ms_Middle_words2Array.append("missile missile missile missile missile missile missile missile missile missile");
    exercises_ms_Middle_words2Array.append("leisure general further hygiene jealous ideally happily library hamster grammar");
    exercises_ms_Middle_words2Array.append("happily jealous ideally married library leisure hygiene grammar missile hamster");

    exercises_ms_Middle_words3Array.append("opinion opinion opinion opinion opinion opinion opinion opinion opinion opinion");
    exercises_ms_Middle_words3Array.append("pastime pastime pastime pastime pastime pastime pastime pastime pastime pastime");
    exercises_ms_Middle_words3Array.append("pharaoh pharaoh pharaoh pharaoh pharaoh pharaoh pharaoh pharaoh pharaoh pharaoh");
    exercises_ms_Middle_words3Array.append("quality quality quality quality quality quality quality quality quality quality");
    exercises_ms_Middle_words3Array.append("realize realize realize realize realize realize realize realize realize realize");
    exercises_ms_Middle_words3Array.append("receipt receipt receipt receipt receipt receipt receipt receipt receipt receipt");
    exercises_ms_Middle_words3Array.append("receive receive receive receive receive receive receive receive receive receive");
    exercises_ms_Middle_words3Array.append("scenery scenery scenery scenery scenery scenery scenery scenery scenery scenery");
    exercises_ms_Middle_words3Array.append("similar similar similar similar similar similar similar similar similar similar");
    exercises_ms_Middle_words3Array.append("success success success success success success success success success success");
    exercises_ms_Middle_words3Array.append("village village village village village village village village village village");
    exercises_ms_Middle_words3Array.append("weather weather weather weather weather weather weather weather weather weather");
    exercises_ms_Middle_words3Array.append("success pastime quality realize scenery receive receipt similar opinion pharaoh");
    exercises_ms_Middle_words3Array.append("receipt village success quality similar scenery receive weather pharaoh realize");

    exercises_ms_Big_wordsArray.append("business business business business business business business business business business");
    exercises_ms_Big_wordsArray.append("calendar calendar calendar calendar calendar calendar calendar calendar calendar calendar");
    exercises_ms_Big_wordsArray.append("describe describe describe describe describe describe describe describe describe describe");
    exercises_ms_Big_wordsArray.append("espresso espresso espresso espresso espresso espresso espresso espresso espresso espresso");
    exercises_ms_Big_wordsArray.append("familiar familiar familiar familiar familiar familiar familiar familiar familiar familiar");
    exercises_ms_Big_wordsArray.append("familiar familiar familiar familiar familiar familiar familiar familiar familiar familiar");
    exercises_ms_Big_wordsArray.append("guidance guidance guidance guidance guidance guidance guidance guidance guidance guidance");
    exercises_ms_Big_wordsArray.append("honorary honorary honorary honorary honorary honorary honorary honorary honorary honorary");
    exercises_ms_Big_wordsArray.append("humorous humorous humorous humorous humorous humorous humorous humorous humorous humorous");
    exercises_ms_Big_wordsArray.append("lollipop lollipop lollipop lollipop lollipop lollipop lollipop lollipop lollipop lollipop");
    exercises_ms_Big_wordsArray.append("marriage marriage marriage marriage marriage marriage marriage marriage marriage marriage");
    exercises_ms_Big_wordsArray.append("misspell misspell misspell misspell misspell misspell misspell misspell misspell misspell misspell");
    exercises_ms_Big_wordsArray.append("espresso guidance describe calendar familiar business humorous grateful honorary");
    exercises_ms_Big_wordsArray.append("familiar marriage lollipop grateful guidance humorous espresso misspell honorary");

    exercises_ms_Big_words2Array.append("mountain mountain mountain mountain mountain mountain mountain mountain mountain mountain");
    exercises_ms_Big_words2Array.append("neighbor neighbor neighbor neighbor neighbor neighbor neighbor neighbor neighbor neighbor");
    exercises_ms_Big_words2Array.append("nowadays nowadays nowadays nowadays nowadays nowadays nowadays nowadays nowadays nowadays");
    exercises_ms_Big_words2Array.append("obedient obedient obedient obedient obedient obedient obedient obedient obedient obedient");
    exercises_ms_Big_words2Array.append("occasion occasion occasion occasion occasion occasion occasion occasion occasion occasion");
    exercises_ms_Big_words2Array.append("official official official official official official official official official official");
    exercises_ms_Big_words2Array.append("ordinary ordinary ordinary ordinary ordinary ordinary ordinary ordinary ordinary ordinary");
    exercises_ms_Big_words2Array.append("parallel parallel parallel parallel parallel parallel parallel parallel parallel parallel");
    exercises_ms_Big_words2Array.append("pavilion pavilion pavilion pavilion pavilion pavilion pavilion pavilion pavilion pavilion");
    exercises_ms_Big_words2Array.append("personal personal personal personal personal personal personal personal personal personal");
    exercises_ms_Big_words2Array.append("physical physical physical physical physical physical physical physical physical physical");
    exercises_ms_Big_words2Array.append("pleasant pleasant pleasant pleasant pleasant pleasant pleasant pleasant pleasant pleasant");
    exercises_ms_Big_words2Array.append("pavilion neighbor mountain ordinary obedient nowadays official occasion parallel");
    exercises_ms_Big_words2Array.append("pavilion obedient physical official parallel ordinary personal occasion pleasant");

    exercises_ms_Big_words3Array.append("possible possible possible possible possible possible possible possible possible possible");
    exercises_ms_Big_words3Array.append("publicly publicly publicly publicly publicly publicly publicly publicly publicly publicly");
    exercises_ms_Big_words3Array.append("remember remember remember remember remember remember remember remember remember");
    exercises_ms_Big_words3Array.append("roommate roommate roommate roommate roommate roommate roommate roommate roommate");
    exercises_ms_Big_words3Array.append("schedule schedule schedule schedule schedule schedule schedule schedule schedule schedule");
    exercises_ms_Big_words3Array.append("separate separate separate separate separate separate separate separate separate separate");
    exercises_ms_Big_words3Array.append("strategy strategy strategy strategy strategy strategy strategy strategy strategy strategy");
    exercises_ms_Big_words3Array.append("surprise surprise surprise surprise surprise surprise surprise surprise surprise surprise");
    exercises_ms_Big_words3Array.append("tendency tendency tendency tendency tendency tendency tendency tendency tendency tendency");
    exercises_ms_Big_words3Array.append("tomorrow tomorrow tomorrow tomorrow tomorrow tomorrow tomorrow tomorrow tomorrow tomorrow");
    exercises_ms_Big_words3Array.append("valuable valuable valuable valuable valuable valuable valuable valuable valuable valuable");
    exercises_ms_Big_words3Array.append("wherever wherever wherever wherever wherever wherever wherever wherever wherever wherever");
    exercises_ms_Big_words3Array.append("separate possible remember publicly schedule tendency surprise roommate strategy");
    exercises_ms_Big_words3Array.append("strategy tendency schedule valuable surprise tomorrow separate publicly wherever");

    exercises_ms_Large_wordsArray.append("apartment apartment apartment apartment apartment apartment apartment apartment");
    exercises_ms_Large_wordsArray.append("basically basically basically basically basically basically basically basically basically basically");
    exercises_ms_Large_wordsArray.append("beginning beginning beginning beginning beginning beginning beginning beginning beginning");
    exercises_ms_Large_wordsArray.append("challenge challenge challenge challenge challenge challenge challenge challenge challenge");
    exercises_ms_Large_wordsArray.append("chauffeur chauffeur chauffeur chauffeur chauffeur chauffeur chauffeur chauffeur chauffeur");
    exercises_ms_Large_wordsArray.append("colleague colleague colleague colleague colleague colleague colleague colleague colleague");
    exercises_ms_Large_wordsArray.append("conscious conscious conscious conscious conscious conscious conscious conscious conscious");
    exercises_ms_Large_wordsArray.append("copyright copyright copyright copyright copyright copyright copyright copyright copyright");
    exercises_ms_Large_wordsArray.append("criticism criticism criticism criticism criticism criticism criticism criticism criticism criticism");
    exercises_ms_Large_wordsArray.append("curiosity curiosity curiosity curiosity curiosity curiosity curiosity curiosity curiosity curiosity");
    exercises_ms_Large_wordsArray.append("difficult difficult difficult difficult difficult difficult difficult difficult difficult difficult");
    exercises_ms_Large_wordsArray.append("disappear disappear disappear disappear disappear disappear disappear disappear disappear");
    exercises_ms_Large_wordsArray.append("basically copyright colleague challenge beginning conscious apartment chauffeur");
    exercises_ms_Large_wordsArray.append("copyright disappear chauffeur curiosity criticism difficult conscious colleague");

    exercises_ms_Large_words2Array.append("embarrass embarrass embarrass embarrass embarrass embarrass embarrass embarrass embarrass");
    exercises_ms_Large_words2Array.append("excellent excellent excellent excellent excellent excellent excellent excellent excellent excellent");
    exercises_ms_Large_words2Array.append("financial financial financial financial financial financial financial financial financial financial");
    exercises_ms_Large_words2Array.append("generally generally generally generally generally generally generally generally generally generally");
    exercises_ms_Large_words2Array.append("glamorous glamorous glamorous glamorous glamorous glamorous glamorous glamorous glamorous");
    exercises_ms_Large_words2Array.append("immediate immediate immediate immediate immediate immediate immediate immediate immediate");
    exercises_ms_Large_words2Array.append("introduce introduce introduce introduce introduce introduce introduce introduce introduce introduce");
    exercises_ms_Large_words2Array.append("knowledge knowledge knowledge knowledge knowledge knowledge knowledge knowledge knowledge");
    exercises_ms_Large_words2Array.append("lightning lightning lightning lightning lightning lightning lightning lightning lightning lightning");
    exercises_ms_Large_words2Array.append("luxurious luxurious luxurious luxurious luxurious luxurious luxurious luxurious luxurious luxurious");
    exercises_ms_Large_words2Array.append("naturally naturally naturally naturally naturally naturally naturally naturally naturally naturally");
    exercises_ms_Large_words2Array.append("necessary necessary necessary necessary necessary necessary necessary necessary necessary necessary");
    exercises_ms_Large_words2Array.append("introduce excellent embarrass generally glamorous knowledge financial immediate");
    exercises_ms_Large_words2Array.append("immediate luxurious naturally knowledge introduce glamorous necessary lightning");

    exercises_ms_Large_words3Array.append("physician physician physician physician physician physician physician physician physician physician");
    exercises_ms_Large_words3Array.append("preferred preferred preferred preferred preferred preferred preferred preferred preferred preferred");
    exercises_ms_Large_words3Array.append("professor professor professor professor professor professor professor professor professor professor");
    exercises_ms_Large_words3Array.append("raspberry raspberry raspberry raspberry raspberry raspberry raspberry raspberry raspberry raspberry");
    exercises_ms_Large_words3Array.append("realistic realistic realistic realistic realistic realistic realistic realistic realistic realistic");
    exercises_ms_Large_words3Array.append("recognize recognize recognize recognize recognize recognize recognize recognize recognize recognize");
    exercises_ms_Large_words3Array.append("recommend recommend recommend recommend recommend recommend recommend recommend recommend recommend");
    exercises_ms_Large_words3Array.append("secretary secretary secretary secretary secretary secretary secretary secretary secretary secretary");
    exercises_ms_Large_words3Array.append("sincerely sincerely sincerely sincerely sincerely sincerely sincerely sincerely sincerely sincerely");
    exercises_ms_Large_words3Array.append("technicue technicue technicue technicue technicue technicue technicue technicue technicue technicue");
    exercises_ms_Large_words3Array.append("temporary temporary temporary temporary temporary temporary temporary temporary temporary temporary");
    exercises_ms_Large_words3Array.append("therefore therefore therefore therefore therefore therefore therefore therefore therefore therefore");
//    exercises_ms_Large_words3Array("");
//    exercises_ms_Large_words3Array("");

    //QJsonObject lesson_ms_tiny_Object;
    lesson_ms_tiny_Object["name"] = "Tiny words";
    lesson_ms_tiny_Object["exercises"] = exercises_ms_Tiny_wordsArray;

    //QJsonObject lesson_ms_tiny2_Object;
    lesson_ms_tiny2_Object["name"] = "Tiny words 2";
    lesson_ms_tiny2_Object["exercises"] = exercises_ms_Tiny_words2Array;

    //QJsonObject lesson_ms_small_Object;
    lesson_ms_small_Object["name"] = "Small words";
    lesson_ms_small_Object["exercises"] = exercises_ms_Small_wordsArray;

    //QJsonObject lesson_ms_small2_Object;
    lesson_ms_small2_Object["name"] = "Small words 2";
    lesson_ms_small2_Object["exercises"] = exercises_ms_Small_words2Array;

    //QJsonObject lesson_ms_small3_Object;
    lesson_ms_small3_Object["name"] = "Small words 3";
    lesson_ms_small3_Object["exercises"] = exercises_ms_Small_words3Array;

    //QJsonObject lesson_ms_middle_Object;
    lesson_ms_middle_Object["name"] = "Muddke words";
    lesson_ms_middle_Object["exercises"] = exercises_ms_Middle_wordsArray;

    //QJsonObject lesson_ms_middle2_Object;
    lesson_ms_middle2_Object["name"] = "Muddke words 2";
    lesson_ms_middle2_Object["exercises"] = exercises_ms_Middle_words2Array;

    //QJsonObject lesson_ms_middle3_Object;
    lesson_ms_middle3_Object["name"] = "Muddke words 3";
    lesson_ms_middle3_Object["exercises"] = exercises_ms_Middle_words3Array;

    //QJsonObject lesson_ms_big_Object;
    lesson_ms_big_Object["name"] = "Big words";
    lesson_ms_big_Object["exercises"] = exercises_ms_Big_wordsArray;

    //QJsonObject lesson_ms_big2_Object;
    lesson_ms_big2_Object["name"] = "Big words 2";
    lesson_ms_big2_Object["exercises"] = exercises_ms_Big_words2Array;

    //QJsonObject lesson_ms_big3_Object;
    lesson_ms_big3_Object["name"] = "Big words 3";
    lesson_ms_big3_Object["exercises"] = exercises_ms_Big_words3Array;

    //QJsonObject lesson_ms_large_Object;
    lesson_ms_large_Object["name"] = "Large words";
    lesson_ms_large_Object["exercises"] = exercises_ms_Large_wordsArray;

    //QJsonObject lesson_ms_large2_Object;
    lesson_ms_large2_Object["name"] = "Large words 2";
    lesson_ms_large2_Object["exercises"] = exercises_ms_Large_words2Array;

    //QJsonObject lesson_ms_large3_Object;
    lesson_ms_large3_Object["name"] = "Large words 3";
    lesson_ms_large3_Object["exercises"] = exercises_ms_Large_words3Array;

    lessons_ms_Array.append(lesson_ms_tiny_Object);
    lessons_ms_Array.append(lesson_ms_tiny2_Object);
    lessons_ms_Array.append(lesson_ms_small_Object);
    lessons_ms_Array.append(lesson_ms_small2_Object);
    lessons_ms_Array.append(lesson_ms_small3_Object);
    lessons_ms_Array.append(lesson_ms_middle_Object);
    lessons_ms_Array.append(lesson_ms_middle2_Object);
    lessons_ms_Array.append(lesson_ms_middle3_Object);
    lessons_ms_Array.append(lesson_ms_big_Object);
    lessons_ms_Array.append(lesson_ms_big2_Object);
    lessons_ms_Array.append(lesson_ms_big3_Object);
    lessons_ms_Array.append(lesson_ms_large_Object);
    lessons_ms_Array.append(lesson_ms_large2_Object);
    lessons_ms_Array.append(lesson_ms_large3_Object);

    coursesObject["name"] = "courses";

    courseObject["course"] = "English";
    courseObject["lessons"] = lessons_ms_Array;


    newCourseObject["course"] = "English of mistakes";
    newCourseObject["lessons"] = lessons_ms_Array;
    QJsonArray coursesArray = coursesObject["courses"].toArray();
    coursesArray.append(courseObject);
    coursesArray.append(newCourseObject);

    coursesObject["courses"] = coursesArray;

    QJsonDocument document(coursesObject);

    QFile jsonFile("course.json");
    if (jsonFile.open(QIODevice::WriteOnly)) {
        jsonFile.write(document.toJson());
        jsonFile.close();

        qDebug() << "The data is stored in a JSON file.";
    } else {
        qWarning() << "Error opening JSON file for writing.";
    }
}
