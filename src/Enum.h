#pragma once
//�V�[���̎�ނ� "enum "�Œ�`.
enum eScene {
    Title,  //�^�C�g�����
    ScenarioDemo, //�V�i���I�f��
    Map,   //�}�b�v���
    Battle, //�퓬���
    ScenarioEndDemo, //�V�i���I�G���h�f��
    Intermission, //�C���^�[�~�b�V�������
};

enum MapState {
    Nothing,    //�Ֆʏ�ɉ����Ȃ�
    Friend,     //�����L�����N�^�[
    Enemy,      //�G�L�����N�^�[
};