module.exports = function (grunt) {
  grunt.registerTask('patternlab', [
    'shell:patternlabComposer',
    'shell:patternlab'
  ]);
};
